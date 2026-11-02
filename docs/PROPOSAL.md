# Project Proposal: Memory Management Simulator

**Team:** PageMasters
**Members:** Mahdee Haque (242-115-247, team leader), Tarek Ahmed Oyan (242-115-248)
**Course:** Operating System Lab (CSE 322), Metropolitan University

## Problem
Virtual memory and page replacement are hard to understand from theory alone.
It is difficult to see which page is evicted, why a page fault happens, and why
one algorithm performs better than another on the same workload.

## Solution
A terminal-based simulator in C++17 that takes a page reference string and a
number of frames, runs FIFO, LRU and Optimal page replacement, and shows the
frame contents, hit or fault, and victim page at every step. It compares the
algorithms and generates workloads (sequential, random, looping) with a report,
generated from the computed numbers, on which algorithm performs best and why.

## Features
- Must: input with validation, FIFO, LRU, Optimal, step table, ratios, comparison table
- Should: Clock algorithm, Belady's anomaly demo, frame-size comparison
- Could: workload generator and generated report, address translation and TLB

## Team roles
- Mahdee (Tech Lead, Git Captain): project setup, input and validation, FIFO,
  step table, Belady's anomaly demo, Clock, frame-size comparison
- Tarek (QA, Docs Owner): LRU, Optimal, ratios and comparison table, workload
  generator and report
Both members write tests, review each other's pull requests, and attend a
weekly teach-back.
