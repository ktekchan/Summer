# Mac-Learning

A simple MAC learning algorithm. <br/>
It uses a dictionary that maps from an Ethernet address to a switch port. <br/>


<br/>Input begins with a single line that indicates N, the number of packets to be
processed by the algorithm. Each of the N subsequent lines represents a packet
to be processed and consists of an input port number Pin (as a decimal number),
a space, the destination Ethernet address D, a space, and the source Ethernet
address S, each expressed as 6 pairs of hex digits delimited by colons.<br/>

<br/>The output consists of N lines, each of which is one of the strings "drop" or
"flood" or a decimal number (representing Pout).<br/>
