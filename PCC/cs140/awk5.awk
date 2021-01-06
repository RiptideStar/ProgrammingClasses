#awk command: awk -f awk5.awk test-awk.txt

BEGIN {
    count = 0;
}
{
    for (i = 1; i <= NF; i++) {
        #match field with two consecutive vowels
        if (tolower($i) ~ /[aeiou]{2}/) {
            count++;
        }
    }
}
END {
    print count;
}