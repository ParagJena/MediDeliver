# MediDeliver

MediDeliver is a console-based Medicine Delivery Management System developed in C++.

## Project Overview

MediDeliver manages the complete flow of a medicine delivery order, starting from medicine selection and cart management through payment, order processing, delivery assignment, and delivery completion.

The application uses object-oriented programming, STL containers, algorithms, exception handling, file handling, Linux tools, Makefile-based compilation, and Bash scripting.

## Features

- Medicine inventory management
- Medicine search
- Medicine sorting by price
- Customer management
- Shopping cart management
- Add and remove medicines from cart
- Order creation
- Payment processing
- Order status management
- Delivery queue management
- Delivery agent assignment
- Delivery status tracking
- File-based data persistence
- Exception handling
- Persistent medicine stock

## Technologies Used

- C++
- C++17
- STL
- Linux
- Bash
- Git
- Make

## Project Structure

```text
MediDeliver/
├── include/
│   ├── Cart.h
│   ├── Customer.h
│   ├── Delivery.h
│   ├── DeliveryQueue.h
│   ├── FileManager.h
│   ├── Medicine.h
│   ├── Order.h
│   ├── Payment.h
│   └── Pharmacy.h
│
├── src/
│   ├── Cart.cpp
│   ├── Customer.cpp
│   ├── Delivery.cpp
│   ├── DeliveryQueue.cpp
│   ├── FileManager.cpp
│   ├── Medicine.cpp
│   ├── Order.cpp
│   ├── Payment.cpp
│   ├── Pharmacy.cpp
│   └── main.cpp
│
├── data/
│   ├── customers.txt
│   ├── medicines.txt
│   ├── orders.txt
│   └── payments.txt
│
├── build/
├── Makefile
├── deploy.sh
└── README.md
