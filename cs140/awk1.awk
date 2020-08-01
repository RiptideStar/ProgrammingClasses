# awk command: awk -f awk1.awk test-awk.txt

{
    if(NR >= 530 && NR <= 540)
        print "PCC FILE" $0;
}