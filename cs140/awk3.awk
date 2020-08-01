#awk command: awk -f awk3.awk test-awk.txt

{
    for (i = 1; i <= NF; i++) {
        #we have the fields, now we match the fields
        if ($i ~ "^[A-Z]+$") {
            #for the capital strings, we keep the first capital, then make every other letter lowercase
            printf substr($i,1,1) tolower(substr($i,2)) OFS
        }
        else {
            #print it normally
            printf $i OFS
        }
    }
    print ""
}