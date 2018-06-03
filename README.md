# sann

This repository provides a brief introduction to Synchronous Neural Networks (SANNs).

## Publications and Benchmarks

This work was submitted to ACM-IEEE MEMOCODE 2018. The benchmarks referred to at this paper may be found in this repository under the `MEMOCODE_2018_Benchmarks` folder.

## About

Neural networks are being used in Cyber-Physical Systems (CPSs) to influence
real-time decisions with safety implications. Consequently, there has
been a convergence of AI and formal methods to ensure that such
applications operate safely at all times. This has led to the development of new
techniques for functional verification of AI-based CPS [1]. However,
 the issue of timing verification has received scant attention. 

This repository provides a proposal for developing neural networks with timed
semantics called Synchronous Artificial Neural Networks, or SANNs. 
Our approach develops periodic networks,
where the response time of a network may be between 1-tick (called
_mono-periodic_ networks) to _n_-ticks (called
_multi-periodic_ networks. We propose a timing semantics of such
networks using Worst-Case Reaction Time (WCRT) algebra [2]. Multi-periodic networks are
introduced to reduce system reaction times, while keeping
response times within their specified deadlines. 

For complex CPS, we propose meta neural networks for designing concurrent applications where the output from
one network influences other networks. We provide several alternative
architectures and study such systems. Overall, this word develops a new approach
for the design of time predictable CPS involving interacting 
AI modules.

As this is the first work on synchronous neural networks,
there are some limitations and hence several avenues
for future research exist. First, all benchmarks use off-line learning. We are already
working on developing techniques for on-line learning in Esterel. A
second limitation is that we are relying on ``compiling away'' Esterel
concurrency, which is not ideal for many-core processors. We will develop parallel implementations
of SANN in the near future.

1. S. A. Seshia, D. Sadigh, and S. S. Sastry, “Towards verified artificial
intelligence,” arXiv preprint arXiv:1606.08514, 2016.
2. J. Wang, M. Mendler, P. Roop, and B. Bodin, “Timing analysis of syn- chronous programs using wcrt algebra: Scalability through abstraction,” ACM Transactions on Embedded Computing Systems (TECS), vol. 16, no. 5s, p. 177, 2017