while (z + y == x)
{
    if (z < x)
        return "negative";
    else if (z > x)
        return "positive";
    else
        return;
}
goto bar;
label: foo++;
