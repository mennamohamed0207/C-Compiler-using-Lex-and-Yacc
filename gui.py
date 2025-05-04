import tkinter as tk
from tkinter import ttk, messagebox, filedialog
import subprocess
import threading
import queue
import os
import time

class CompilerGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Compiler GUI")
        self.root.geometry("1000x700")
        
        # Execution queue for thread-safe operations
        self.queue = queue.Queue()
        self.current_file = None
        
        # Initialize widgets first
        self.code_editor = None
        self.create_widgets()
        
        # Then create menu bar that depends on widgets
        self.create_menu_bar()
        
        # Start queue checker
        self.check_queue()
        
        # Process tracking
        self.compiler_process = None
        self.stop_compilation_flag = False

    def create_widgets(self):
        # Code editor
        self.code_editor = tk.Text(self.root, font=('Consolas', 12))
        self.code_editor.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Button frame
        btn_frame = tk.Frame(self.root)
        btn_frame.pack(fill=tk.X, padx=5, pady=5)
        
        self.compile_btn = tk.Button(
            btn_frame, 
            text="Compile", 
            command=self.start_compilation,
            bg="#4CAF50",
            fg="white"
        )
        self.compile_btn.pack(side=tk.LEFT, padx=5)
        
        self.stop_btn = tk.Button(
            btn_frame,
            text="Stop",
            command=self.stop_compilation,
            state=tk.DISABLED,
            bg="#F44336",
            fg="white"
        )
        self.stop_btn.pack(side=tk.LEFT)
        
        # Status label
        self.status_var = tk.StringVar(value="🟢 Ready")
        self.status_label = tk.Label(
            btn_frame,
            textvariable=self.status_var,
            anchor=tk.W
        )
        self.status_label.pack(side=tk.LEFT, expand=True, fill=tk.X, padx=10)
        
        # Output tabs
        self.tabs = ttk.Notebook(self.root)
        self.tabs.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Create tabs
        self.asm_tab = self.create_tab("Assembly Output")
        self.symbol_tab = self.create_tab("Symbol Table")
        self.error_tab = self.create_tab("Errors")
        self.console_tab = self.create_tab("Console")
        
    def create_menu_bar(self):
        menubar = tk.Menu(self.root)
        
        # File menu
        file_menu = tk.Menu(menubar, tearoff=0)
        file_menu.add_command(label="New", command=self.new_file, accelerator="Ctrl+N")
        file_menu.add_command(label="Open", command=self.open_file, accelerator="Ctrl+O")
        file_menu.add_command(label="Save", command=self.save_file, accelerator="Ctrl+S")
        file_menu.add_command(label="Save As", command=self.save_file_as)
        file_menu.add_separator()
        file_menu.add_command(label="Exit", command=self.root.quit)
        menubar.add_cascade(label="File", menu=file_menu)
        
        # # Edit menu (only add if code_editor exists)
        # if hasattr(self, 'code_editor'):
        #     edit_menu = tk.Menu(menubar, tearoff=0)
        #     edit_menu.add_command(label="Undo", command=self.code_editor.edit_undo, accelerator="Ctrl+Z")
        #     edit_menu.add_command(label="Redo", command=self.code_editor.edit_redo, accelerator="Ctrl+Y")
        #     edit_menu.add_separator()
        #     edit_menu.add_command(label="Cut", command=self.cut_text, accelerator="Ctrl+X")
        #     edit_menu.add_command(label="Copy", command=self.copy_text, accelerator="Ctrl+C")
        #     edit_menu.add_command(label="Paste", command=self.paste_text, accelerator="Ctrl+V")
        #     menubar.add_cascade(label="Edit", menu=edit_menu)
        
        self.root.config(menu=menubar)
        
        # Bind keyboard shortcuts
        self.root.bind_all("<Control-n>", lambda e: self.new_file())
        self.root.bind_all("<Control-o>", lambda e: self.open_file())
        self.root.bind_all("<Control-s>", lambda e: self.save_file())
        
    def create_tab(self, name):
        frame = ttk.Frame(self.tabs)
        text = tk.Text(frame, wrap=tk.WORD, font=('Consolas', 10))
        scroll = ttk.Scrollbar(frame, command=text.yview)
        text.configure(yscrollcommand=scroll.set)
        
        scroll.pack(side=tk.RIGHT, fill=tk.Y)
        text.pack(fill=tk.BOTH, expand=True)
        
        self.tabs.add(frame, text=name)
        return text
    
    # File operations
    def new_file(self):
        self.code_editor.delete("1.0", tk.END)
        self.current_file = None
        self.status_var.set("🟢 New file created")
        self.log("Created new file")
        
    def open_file(self):
        file_path = filedialog.askopenfilename(
            filetypes=[("C Files", "*.c"), ("Text Files", "*.txt"), ("All Files", "*.*")]
        )
        if file_path:
            try:
                with open(file_path, 'r') as f:
                    content = f.read()
                self.code_editor.delete("1.0", tk.END)
                self.code_editor.insert(tk.END, content)
                self.current_file = file_path
                self.status_var.set(f"🟢 Opened: {os.path.basename(file_path)}")
                self.log(f"Opened file: {file_path}")
            except Exception as e:
                self.log(f"Error opening file: {str(e)}")
                messagebox.showerror("Error", f"Failed to open file:\n{str(e)}")
    
    def save_file(self):
        if self.current_file:
            self._save_to_file(self.current_file)
        else:
            self.save_file_as()
    
    def save_file_as(self):
        file_path = filedialog.asksaveasfilename(
            defaultextension=".c",
            filetypes=[("C Files", "*.c"), ("Text Files", "*.txt"), ("All Files", "*.*")]
        )
        if file_path:
            self.current_file = file_path
            self._save_to_file(file_path)
    
    def _save_to_file(self, file_path):
        try:
            with open(file_path, 'w') as f:
                f.write(self.code_editor.get("1.0", tk.END))
            self.status_var.set(f"🟢 Saved: {os.path.basename(file_path)}")
            self.log(f"Saved file: {file_path}")
        except Exception as e:
            self.log(f"Error saving file: {str(e)}")
            messagebox.showerror("Error", f"Failed to save file:\n{str(e)}")
    
    # Edit operations
    def cut_text(self):
        self.code_editor.event_generate("<<Cut>>")
    
    def copy_text(self):
        self.code_editor.event_generate("<<Copy>>")
    
    def paste_text(self):
        self.code_editor.event_generate("<<Paste>>")
    
    # Compilation and output handling
    def check_queue(self):
        """Process events from the queue in the main thread"""
        try:
            while True:
                func, args = self.queue.get_nowait()
                func(*args)
        except queue.Empty:
            pass
        self.root.after(100, self.check_queue)
    
    def log(self, message):
        """Thread-safe logging to console tab"""
        self.queue.put((self._log, (message,)))
    
    def _log(self, message):
        """Actual logging implementation (must run in main thread)"""
        timestamp = time.strftime("%H:%M:%S")
        self.console_tab.insert(tk.END, f"[{timestamp}] {message}\n")
        self.console_tab.see(tk.END)
    
    def start_compilation(self):
        """Start compilation process in a separate thread"""
        code = self.code_editor.get("1.0", tk.END).strip()
        if not code:
            messagebox.showwarning("Warning", "Please enter code to compile")
            return
            
        self.log("Starting compilation...")
        self.compile_btn.config(state=tk.DISABLED)
        self.stop_btn.config(state=tk.NORMAL)
        self.status_var.set("🟠 Compiling...")
        
        # Clear previous outputs
        for tab in [self.asm_tab, self.symbol_tab, self.error_tab]:
            tab.delete("1.0", tk.END)
        
        # Start compilation in background thread
        threading.Thread(
            target=self.run_compiler,
            args=(code,),
            daemon=True
        ).start()
    
    def stop_compilation(self):
        """Stop the running compilation process"""
        self.log("User requested compilation stop")
        self.stop_compilation_flag = True
        if self.compiler_process:
            try:
                self.compiler_process.terminate()
                self.log("Compiler process terminated")
            except Exception as e:
                self.log(f"Error terminating process: {str(e)}")
    
    def run_compiler(self, code):
        """Run the compiler with the given source code"""
        try:
            self.stop_compilation_flag = False
            
            # Create the process with stdin pipe
            self.compiler_process = subprocess.Popen(
                ["mycompiler.exe","test"],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                creationflags=subprocess.CREATE_NO_WINDOW
            )
            
            self.log("Compiler process started")
            
            # Send the code to the compiler's stdin
            self.compiler_process.stdin.write(code)
            self.compiler_process.stdin.close()
            self.log("Source code sent to compiler")
            
            # Wait for completion with timeout
            start_time = time.time()
            timeout = 30  # seconds
            
            while True:
                if self.stop_compilation_flag:
                    break
                    
                return_code = self.compiler_process.poll()
                if return_code is not None:
                    elapsed = time.time() - start_time
                    self.log(f"Compiler exited with code {return_code} (took {elapsed:.2f}s)")
                    break
                    
                if time.time() - start_time > timeout:
                    self.log("Compiler timeout reached")
                    self.compiler_process.terminate()
                    break
                    
                time.sleep(0.1)
            
            # Process results
            self.process_results()
            
        except Exception as e:
            self.log(f"Error during compilation: {str(e)}")
            self.queue.put((
                messagebox.showerror,
                ("Error", f"Compilation failed: {str(e)}")
            ))
        finally:
            self.queue.put((self.cleanup, ()))
    
    def process_results(self):
        """Process the output files created by the compiler"""
        self.log("Processing compiler outputs...")
        
        # Check and display each output file
        output_files = [
            ("assembly_test.txt", self.asm_tab),
            ("symbol_table_test.txt", self.symbol_tab),
            ("errors.txt", self.error_tab)
        ]
        
        for filename, tab in output_files:
            try:
                if os.path.exists(filename):
                    with open(filename, 'r') as f:
                        content = f.read()
                    self.queue.put((
                        self.update_tab,
                        (tab, content)
                    ))
                    self.log(f"Loaded {filename}")
                else:
                    self.log(f"File not found: {filename}")
            except Exception as e:
                self.log(f"Error reading {filename}: {str(e)}")
    
    def update_tab(self, tab, content):
        """Update a text tab with new content"""
        tab.delete("1.0", tk.END)
        tab.insert(tk.END, content)
    
    def cleanup(self):
        """Clean up after compilation"""
        self.compile_btn.config(state=tk.NORMAL)
        self.stop_btn.config(state=tk.DISABLED)
        self.compiler_process = None
        self.stop_compilation_flag = False
        
        if self.compiler_process and self.compiler_process.poll() is None:
            self.compiler_process.terminate()
        
        self.status_var.set("🟢 Ready")
        self.log("Compilation finished")

if __name__ == "__main__":
    root = tk.Tk()
    app = CompilerGUI(root)
    root.mainloop()