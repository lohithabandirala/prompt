
set ns [new Simulator]

$ns color 1 Blue

set nf [open out.tr w]
set namfile [open out.nam w]

$ns trace-all $nf
$ns namtrace-all $namfile

proc finish {} {
global ns nf namfile
$ns flush-trace
close $nf
close $namfile
exec nam out.nam &
exit 0
}

set n0 [$ns node]
set n1 [$ns node]

$ns at 0.0 "$n0 label Sender"
$ns at 0.0 "$n1 label Receiver"

$ns duplex-link $n0 $n1 1Mb 10ms DropTail

set tcp [new Agent/TCP]
$tcp set window_ 1
$tcp set maxcwnd_ 1
$tcp set fid_ 1

set sink [new Agent/TCPSink]

$ns attach-agent $n0 $tcp
$ns attach-agent $n1 $sink

$ns connect $tcp $sink

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns at 0.5 "$ftp start"
$ns at 4.5 "$ftp stop"
$ns at 5.0 "finish"

$ns run
