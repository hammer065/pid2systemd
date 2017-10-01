pid2systemd
===========
A program to convert process IDs to systemd unit names

-----------

Usage
-----

    pid2systemd [-s]

 - `-s`: *Optional*, only output service units

PIDs are being read from STDIN, systemd unit names are being echoed on STDOUT.
PIDs without a (service) unit will be echoed back on STDERR.
