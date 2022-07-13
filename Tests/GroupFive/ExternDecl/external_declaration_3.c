*foo() static register extern x = y; y = z; foo = bar; {
    while (x != foo)
        foo += bar;
        bar++;
        return x;
}
