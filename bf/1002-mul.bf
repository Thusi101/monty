,                       At c0 read char
>++++++                 Forward to c1 and add 6             
[<-------->-]           While c1 above 0 decrement c0 8 times and decrement c1 (this turns c0 from ASCII to int) 
[-]                     Decrement c1 to 0 (ready for 2nd input)
,                       At c1 read char
>++++++                 Forward to c2 and add 6             
[<-------->-]           While c2 above 0 decrement c1 8 times and decrement c2 (this turns c1 from ASCII to int)
[-]                     Decrement c2 to 0 (ready for later calculation)
<<[                     While c0 is not null
    >[                  While c1 is not null
        -               Decrement c1
        >+              Forward to c2 and increment
        >+              Forward to c3 and increment
    <<]                 Back to c1 and loop
    >[                  Forward to c2 and while c2 is not null
        -               Decrement c2
        <+              Back to c1 and increment c1 (this transfers c2 back to c1)
    >]                  Back to c2 and loop
    <<-                 Back to c1 and decrement c1
]                       Loop

>>>>++++++              Forward to c4 add 6             
[<++++++++>-]           While c4 above 0 increment c3 8 times and decrement c3 (this turns c3 back to ASCII from int)
<.                      Back to c3 and print
