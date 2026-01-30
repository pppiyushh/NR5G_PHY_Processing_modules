# NR5G PHY Processing Modules

This repository implements selected NR5G uplink PHY processing blocks
with a firmware-oriented design philosophy.

## Design Goals
- Deterministic execution
- Fixed-point arithmetic
- No dynamic memory allocation in hot paths
- Clear, inspectable data flow

## Current Scope
- UL bit scrambling (Gold-sequence inspired, simplified)

## What This Is NOT
- Full 3GPP-compliant stack
- MATLAB-style simulation
- Channel modeling

## Motivation
The goal is to demonstrate firmware-grade PHY implementation suitable
for real-time baseband systems.
