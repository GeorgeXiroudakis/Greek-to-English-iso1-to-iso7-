# Greek-to-English-iso1-to-iso7-
fourth semester assignment

## intro 
This is a translation program from iso8859-7 (including greek characters) to iso8859-1 (latin-1)  

take into account all the unique characteristics of the greek langage such as the pitch sympoles,
the umlauts and both at the same time.
it also translates the diphthong μπ to b and ντ to d.

(all of the above are true for both uper and lowe case characters.)

## use 
takes from stdin input in iso8859-7 and print the translation with iso8859-1 characters.
MAKE SURE to be in an invarioment that uses iso8859-7 inscription to view correctly both the input and the output.

## impimitation 
everything exept the dipthong for speed and simplisity is handled by au array where you get the replacement 
directly by indexing the value you want to replace.

### dipthong
the dipthong is hanled by a fsm (finate state machine) that detects them.
for example if we get μ or ν that can be the start of a dipthong we dont print the replacement but simply move 
to the next state2 and if we get one of those again we remain on state2 if we ge π or τ acordingly we print b or d
and move to state1 again. else if we get something else we move to state1 again but print the characters separate.

the moving between the states is hanled automaticly by the return values.
