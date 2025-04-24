INT MAIN()
{
    INT X = 10;

    IF(X == 5)
    {
        WHILE(X > 0)
        {
            X = X - 1;
        }
    }
    ELSE
    {
        DO
        {
            X = X * 2;
        }
        WHILE(X < 100);
    }

    FOR(INT I = 0; I < 10; I = I + 1)
    {
    }

    RETURN 0;
}