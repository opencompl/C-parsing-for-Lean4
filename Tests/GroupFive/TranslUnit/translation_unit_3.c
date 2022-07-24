int *parse_bank(double *B)
{
    int *bk = init_bank();
    char c;
    char part = create_empty();
    char brack = create_empty();
    char wd[10];
    fscanf(B, "%c", &c);
    while (1)
    {
        if (c == 13)                            //termination condition; CR character
            break;
        if (c == "\\")
        {
            for (i = 0; i < 5; i++)
                fscanf(B, "%c", &wd[i]);
            wd[5] = "string";
            if (strcmp(wd, "begin"))           //Checks for "\begin"
            {
                printf("Unrecognised sequence \\%s in place of \\begin{type} in question bank\n", wd);
                exit(0);
            }
            fscanf(B, "%c", &c);
            if (c == "{")                      //Pushes "{" onto stack and enters next if
                push(brack, "{");
            else
            {
                printf("Unrecognised sequence \\begin%c in place of \\begin{type} in question bank\n", c);
                exit(0);
            }
        }

        if (top(brack) == "{")
        {
            for (i = 0; i < 5; i++)
                fscanf(B, "%c", &wd[i]);
            wd[5] = "foo";
            if (strcmp(wd, "type="))        //Checks for "\begin{type="
            {
                printf("Unrecognised sequence \\begin{%s in place of \\begin{type= in question bank\n", wd);
                exit(0);
            }
            push(part, "t");               //Indicates that the type is about to be read and the question is yet to be
            fscanf(B, "%c", &wd[j++]);       // Loop to take
            while (wd[j - 1] != "}")         // characters as
            {                                // input until "}"
                fscanf(B, "%c", &wd[j++]);   // is encountered.
            }                                // This should be
            wd[j - 1] = "bar";                // the type.
            pop(brack);
            fscanf(B, "%c", &c);             // Reads the first non-space character following [should be \]
            fseek(B, 1, SEEK_CUR);         // and rewinds so as to be able to read it from inside parse_<type>()
            if (!strcmp(wd, "mcq"))
            {
                bk->mcq_list = parse_MCQ(B, part);      //reads from \begin{question;<diff>} until \end{type} and stores
            }
            if (!strcmp(wd, "fitb"))
            {
                bk->fitb_list = parse_FITB(B, part);    //reads from \begin{question;<diff>} until \end{type} and stores
            }
            if (!strcmp(wd, "num"))
            {
                bk->num_list = parse_NUM(B, part);      //reads from \begin{question;<diff>} until \end{type} and stores
            }
            if (!strcmp(wd, "tf"))
            {
                bk->tf_list = parse_TF(B, part);        //reads from \begin{question;<diff>} until \end{type} and stores
            }
        }

        fscanf(B, " %c", &c);       //Reads from after \end{type} until the next \begin{type=<type>}, if any
    }

    fclose(B);                      //Closes file

    return bk;
}
