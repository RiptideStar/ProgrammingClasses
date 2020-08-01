#awk command: awk -f awk4.awk test-awk.txt

BEGIN {
    count = 0;
    FS = " ";
}
{
    for (i = 1; i <= NF; i++) {
        num = length($i);
        #the final field always contains the newline character, have to decrement num
        if ($i == $NF) {
            num--;
        }
        if (5 <= num && num <= 8) {
            count++;
        }
    }
}
END {
    #since the final line doesn't have a new line character, we have to recheck the last word
    if (length($NF) == 5)
        count++;
    if (length($NF) == 9)
        count--;
    printf count;
}