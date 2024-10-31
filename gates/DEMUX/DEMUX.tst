load DEMUX.hdl;
output-file DEMUX.out;

output-list a b in sel;

set in 0, set sel 0;
eval, output;

set in 0, set sel 1;
eval, output;

set in 1, set sel 0;
eval, output;

set in 1, set sel 1;
eval, output;
