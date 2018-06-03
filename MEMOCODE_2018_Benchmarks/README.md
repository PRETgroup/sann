# MEMOCODE_2018_Benchmarks

In this folder, the benchmarks used for the paper are presented.

* `ADDER`:
* `AIBRO`:
* `CNN_darknet`:
* `ESS_EV_Charging_System`:
* `HELLO_RNN`:
* `RABBIT_and_wolf_game`:
* `XOR`:

In general, usage of the neural networks may be done via the following:

1. Install Esterel by....
2. Run the make scripts by ....
3. See that the networks work.

If you are interested in timing, you may follow the following additional steps:

1. Install t-crest by....
2. Run the make scripts by...
3. See that it works.

## Example

1. Go to `MEMOCODE_2018_Benchmarks/XOR/XOR_BlackBox`
2. Run `make main`
3. Run the network: `./main`
4. Output is shown.
5. Run `make wcet`
6. Timing is shown.

## Pre-built

In this repository, pre-built and pre-analysed results are typically available. You may see this by looking at for example
`MEMOCODE_2018_Benchmarks/XOR/XOR_BlackBox/main` (which is a binary built for Ubuntu on Intel) or `MEMOCODE_2018_Benchmarks/XOR/XOR_BlackBox/xor_ann.wca`

