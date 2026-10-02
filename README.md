# MediDeliver

MediDeliver is a console-based Medicine Delivery Management System developed in C++ and implemented on Linux.

## Project Overview

MediDeliver manages the complete flow of a medicine delivery order, starting from medicine selection and customer selection through cart management, payment processing, order confirmation, delivery assignment, delivery tracking, and order completion.

The project demonstrates object-oriented programming, STL containers, iterators, algorithms, exception handling, file handling, Linux system usage, Makefile-based compilation, Bash scripting, Git version control, and a Linux kernel module.

## Architecture

The system follows a modular software architecture:

```text
Customer
    |
    v
MediDeliver Application
    |
    +---- Pharmacy
    |       |
    |       +---- Medicine Inventory
    |
    +---- Cart
    |
    +---- Order Management
    |
    +---- Payment
    |
    +---- Delivery Queue
    |
    +---- Delivery Management
    |
    v
File-Based Data Storage
