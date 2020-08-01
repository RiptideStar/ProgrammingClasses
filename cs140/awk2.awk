#awk command: awk -f awk2.awk test-awk.txt

#so if the line doesn't start with 'Of', we will print the line
!/^(Of)/ {
    print $0;
}