# MediDeliver

## Linux-Based Medicine Delivery Management System

MediDeliver is a console-based Medicine Delivery Management System developed using C++17 and implemented exclusively on Linux.

The system models the complete medicine delivery workflow, including customer selection, pharmacy and medicine management, cart operations, order processing, payment simulation, delivery queue management, delivery tracking, and file-based data persistence.

The project also incorporates Linux development practices such as Makefile-based compilation, Bash scripting, Git version control, and a Linux kernel module.

---

## 1. Project Overview

MediDeliver is designed as a modular software system that demonstrates how a real-world medicine delivery workflow can be implemented using C++ and Linux.

The application provides a menu-driven interface through which a user can:

- Select a customer
- View available medicines
- Search for medicines
- Add medicines to a cart
- View the cart
- Remove medicines from the cart
- Place an order
- Process a simulated payment
- Update medicine stock
- Add orders to a delivery queue
- Assign a delivery agent
- Track delivery status
- View delivery records
- View order history

Project data is stored in text files so that important records remain available after the application is restarted.

---

## 2. Objectives

The main objectives of the project are:

1. Implement a complete software architecture using C++.
2. Apply object-oriented programming principles.
3. Demonstrate STL containers, iterators, and algorithms.
4. Implement exception handling and input validation.
5. Implement file-based data persistence.
6. Demonstrate queue-based delivery processing.
7. Develop and execute the application on Linux.
8. Use Makefiles for compilation.
9. Use Git for version control.
10. Incorporate and demonstrate a Linux kernel module.

---

## 3. System Architecture

The system follows a modular software architecture.

```text
                         MediDeliver
                              |
                +-------------+-------------+
                |             |             |
            Customer       Pharmacy        Cart
                              |
                          Medicines
                              |
                            Order
                              |
                           Payment
                              |
                       Delivery Queue
                              |
                          Delivery
                              |
                       File Storage
