Project-6 threads
=====================
Tristan Wagstaff

parta returns count 0 because my machine can make and print and return in less than 1 second
the results were expected.
partb returns count 10 because each thread is writing over the results from the previous threads
the results were expected because they all take in count sleep then reassign this wil make them all get a value say 2 and then wait just long enough for the others to write 2 and move on before overwritting that 2 again.
partc returns count 40 because each thread can count to 10 before the next thread even starts
I was a little surprised I wasn't entirely sure if there wouldn't be at least a little overlap where one was trying to write say 36 while another was trying to write 38, but I suspected that it could happen.
partd returns count 40 because each thread increments the total count by 1 and then turns over control to another thread. Operated totally as expected, just as an off hand, just a little tidbit I played around with the counting and tried making count a lot further with no threads, and with six threads since I am running a hexcore machine. Alot slower with threads than without it was too be expected with the extra overhead to just count but I just found that interesting.
