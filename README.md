# Locking Tree Problem

![C++](https://img.shields.io/badge/language-C%2B%2B-blue)
![Tree Structure](https://img.shields.io/badge/data%20structure-Tree-brightgreen)
![Complexity](https://img.shields.io/badge/Time%20Complexity-Optimized-lightgrey)

## Overview

The **Locking Tree Problem** involves implementing a set of locking operations on nodes within an M-ary tree. Each node in the tree can be "locked" or "unlocked" by a user, with constraints on how and when nodes can be locked or unlocked, depending on their relationship within the tree.

This project defines three primary operations:

1. **Lock** - Lock a specific node.
2. **Unlock** - Unlock a previously locked node.
3. **UpgradeLock** - Upgrade the lock on a node to include its ancestors if certain conditions are met.

## Problem Statement

### Tree Structure and Problem Context

You have a hierarchical world map represented as an M-ary tree, resembling the structure below:
![Tree Structure](./Locking Tree Problem.png)

### Operations

You need to define three operations on this tree structure:

- `lock(X, uid)`: Locks node `X` for user `uid`.
- `unlock(X, uid)`: Unlocks node `X` if it was locked by the same user.
- `upgradeLock(X, uid)`: Upgrades the lock on node `X` to an ancestor lock if all locked descendants are locked by `uid`.

#### Details of Operations

1. **Lock(X, uid)**:

   - Grants exclusive access to the subtree rooted at `X` for the user `uid`.
   - After a successful lock on `X`:
     - `lock(A, anyUserId)` will fail if `A` is a descendant of `X`.
     - `lock(B, anyUserId)` will fail if `X` is a descendant of `B`.
   - Locking a node that is already locked will fail.

2. **Unlock(X, uid)**:

   - Unlocks the node `X` if it was previously locked by the same user `uid`.
   - Returns `true` if the unlock is successful.

3. **UpgradeLock(X, uid)**:
   - Upgrades the lock on node `X` if:
     - All descendants of `X` that are locked are locked by the same `uid`.
   - Upgrade fails if any locked descendant of `X` is locked by a different user.
   - Once `UpgradeLock` on `X` succeeds, `X` is considered locked by `uid`.

## Project Structure

- **Header Files**: Contains tree structure definitions, operations, and helper functions.
- **Source Code**: Implements the locking logic, including conditions for each operation.
- **Example Scenarios**: Example test cases to validate each operation and edge cases.

## Usage

To compile and run the project, use the following command in your terminal:

```bash
g++ -o locking_tree locking_tree.cpp -std=c++11
./locking_tree

```
