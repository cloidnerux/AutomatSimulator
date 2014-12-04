FSM Simulator
==============

Small finite state machine simulator
Reads a state table from a csv file and simulates the state machine for random inputs

CSV-File format:

state name, next state name for input false, next state name for input true, output for input false, output for input true

Example:

#Example file, lines with # are ignored
a, b, c, 0, 0
b, c, a, 1, 0
c, b, a, 1, 1