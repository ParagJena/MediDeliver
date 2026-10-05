# MediDeliver

## Medicine Delivery Management System

MediDeliver is a Linux-based, console-driven Medicine Delivery Management System developed in **C++**. The project demonstrates modular software design, object-oriented programming, STL data structures and algorithms, exception handling, file I/O, Linux development practices, Git version control, and a separate Linux kernel module.

The application models the core workflow of a medicine-delivery service:

**Customer → Medicine/Pharmacy → Cart → Order → Payment → Delivery Queue → Delivery → File Storage**

---

## 1. Project Purpose

The project was developed as a Wipro corporate-training capstone to apply concepts covered in C++, data structures, Linux, Git, computer architecture, and systems programming.

The main purpose is to demonstrate how a structured C++ application can be designed, built, executed and maintained in a Linux environment while keeping the application modular and understandable.

---

## 2. Objectives

- Develop a complete medicine-delivery workflow in C++.
- Apply object-oriented programming and modular code organization.
- Use STL containers, iterators and algorithms.
- Use exception handling for invalid operations.
- Implement file-based persistence without requiring a database.
- Build and execute the application on Linux.
- Use Makefile-based compilation and a Bash deployment/build script.
- Demonstrate Linux kernel-module concepts through a separate driver component.
- Maintain the project using Git and publish the complete source structure to GitHub.

---

## 3. System Architecture

```text
                    +----------------+
                    |    Customer    |
                    +-------+--------+
                            |
                            v
                    +----------------+
                    |    Pharmacy    |
                    |    Medicine    |
                    +-------+--------+
                            |
                            v
                    +----------------+
                    |      Cart      |
                    +-------+--------+
                            |
                            v
                    +----------------+
                    |     Order      |
                    +-------+--------+
                            |
                            v
                    +----------------+
                    |    Payment     |
                    +-------+--------+
                            |
                            v
                    +----------------+
                    | Delivery Queue |
                    +-------+--------+
                            |
                            v
                    +----------------+
                    |    Delivery    |
                    +-------+--------+
                            |
                            v
                    +----------------+
                    |  File Storage  |
                    +----------------+
```

The architecture separates responsibilities into domain classes instead of placing the complete workflow in one source file.

---

## 4. Order Processing Flow

```text
Select Customer
      |
      v
View / Search Medicine
      |
      v
Add Medicine to Cart
      |
      v
Validate Cart and Stock
      |
      v
Place Order
      |
      v
Process Payment
      |
      v
Create Delivery
      |
      v
Add Order to Delivery Queue
      |
      v
Update Delivery / Order Status
      |
      v
Save Records to Data Files
```

The application provides a console menu for the major user operations.

---

## 5. Project Structure

```text
MediDeliver/
├── include/
│   ├── Medicine.h
│   ├── Customer.h
│   ├── Pharmacy.h
│   ├── Cart.h
│   ├── Order.h
│   ├── Payment.h
│   ├── Delivery.h
│   ├── DeliveryQueue.h
│   └── FileManager.h
│
├── src/
│   ├── Medicine.cpp
│   ├── Customer.cpp
│   ├── Pharmacy.cpp
│   ├── Cart.cpp
│   ├── Order.cpp
│   ├── Payment.cpp
│   ├── Delivery.cpp
│   ├── DeliveryQueue.cpp
│   ├── FileManager.cpp
│   └── main.cpp
│
├── driver/
│   ├── medideliver_driver.c
│   └── Makefile
│
├── data/
│   ├── customers.txt
│   ├── medicines.txt
│   ├── orders.txt
│   ├── payments.txt
│   └── deliveries.txt
│
├── build/
├── backups/
├── Makefile
├── deploy.sh
├── README.md
└── .gitignore
```

The project follows the recommended separation between header files and implementation files: declarations are kept under `include/` and implementations under `src/`.

---

## 6. C++ Class Design

### Medicine

Represents a medicine using:

- Medicine ID
- Name
- Category
- Price
- Stock

Provides accessors, stock modification and display functionality.

### Customer

Represents a customer using:

- Customer ID
- Name
- Phone
- Address

### Pharmacy

Manages a collection of medicines and supports:

- Adding medicines
- Displaying medicines
- Searching by medicine ID
- Reducing stock
- Sorting medicines by price

### Cart

Maintains cart items using a collection of `CartItem` records.

Supports:

- Add medicine
- Remove medicine
- Display cart
- Calculate total
- Check whether the cart is empty
- Clear cart

### Order

Represents an order containing:

- Order ID
- Customer
- Cart items
- Total amount
- Order status

Order status values include:

- Placed
- Confirmed
- OutForDelivery
- Delivered
- Cancelled

### Payment

Represents payment information containing:

- Payment ID
- Order ID
- Amount
- Payment method
- Payment status

Payment status values include:

- Pending
- Successful
- Failed

### Delivery

Represents delivery information containing:

- Delivery ID
- Order ID
- Delivery address
- Delivery agent
- Delivery status

### DeliveryQueue

Provides FIFO processing for delivery orders using `std::queue`.

### FileManager

Centralizes file-related operations such as:

- Creating required data files
- Saving records
- Loading records
- Generating the next order ID
- Generating the next payment ID
- Generating the next delivery ID

---

## 7. C++ Concepts Demonstrated

### Object-Oriented Programming

The application is organized around classes representing real system entities such as Medicine, Customer, Pharmacy, Cart, Order, Payment and Delivery.

The design demonstrates:

- Encapsulation
- Constructors
- Member functions
- Composition
- Class-based modularity
- Access control using private and public members

### Header and Source Separation

Class declarations are stored in `.h` files while implementations are stored in `.cpp` files.

This keeps the codebase organized and follows a conventional C++ project structure.

### Enumerations

Strongly scoped enumerations are used for workflow states:

```text
OrderStatus
PaymentStatus
DeliveryStatus
```

This keeps status values explicit and avoids using unrelated integer constants.

---

## 8. STL and Data Structures

The project uses standard C++ library facilities where they naturally fit the problem.

### `std::vector`

Used for dynamic collections such as:

- Pharmacy medicines
- Cart items
- Loaded customer records
- Loaded order records
- Loaded delivery records

### `std::queue`

`DeliveryQueue` uses `std::queue<int>` to model a FIFO delivery-processing sequence.

```text
First order added → First order processed
```

### Iterators

Iterators are used when traversing and modifying collections, including removing an item from the cart.

### STL Algorithm

`std::sort` is used to sort medicines by price.

The comparison is implemented with a lambda expression.

---

## 9. Exception Handling

The application uses standard C++ exceptions to prevent invalid operations from silently continuing.

Examples include:

- `std::invalid_argument`
  - Invalid cart quantity
  - Invalid order ID

- `std::runtime_error`
  - Insufficient medicine stock
  - Medicine not found in cart
  - Empty delivery queue

Exception handling keeps validation logic close to the operation that can fail and allows `main.cpp` to handle errors at the user-interaction level.

---

## 10. File-Based Persistence

MediDeliver uses text files instead of a database.

The files are stored under `data/`.

| File | Purpose |
|---|---|
| `medicines.txt` | Medicine inventory records |
| `customers.txt` | Customer records |
| `orders.txt` | Order records |
| `payments.txt` | Payment records |
| `deliveries.txt` | Delivery records |

`FileManager` handles initialization and persistence.

This approach makes the project simple to run in a Linux training environment without requiring a separate database server.

### Persistence Workflow

```text
Application
     |
     +---- Read existing records
     |
     +---- Process operation
     |
     +---- Append new records
     |
     +---- Continue with updated data
```

---

## 11. Linux Implementation

The project is designed to run on Linux/Ubuntu.

The Linux training material emphasizes that the Linux kernel is responsible for hardware management, scheduling, devices and networking, while GNU tools provide the shell, compiler and core command-line utilities.

MediDeliver uses this Linux environment for:

- Source-code editing
- Compilation
- Program execution
- File operations
- Build automation
- Kernel-module compilation
- Git operations

Typical tools used include:

```text
bash
g++
make
git
```

Useful Linux inspection commands include:

```bash
uname -a
uname -r
pwd
ls
find
grep
```

---

## 12. Build Toolchain

The project follows a simple build pipeline:

```text
C++ Source Files
       |
       v
      g++
       |
       v
Object / Executable Build
       |
       v
MediDeliver Application
```

The root `Makefile` provides repeatable compilation instead of requiring every source file to be compiled manually.

This reflects the training material's emphasis on the C++ build toolchain and organized project structure.

---

## 13. Build the Application

From the project root:

```bash
cd ~/MediDeliver
make
```

If the project build completes successfully, run the application using the generated executable defined by the Makefile.

To inspect available Make targets:

```bash
make help
```

If the project Makefile does not provide a `help` target, use:

```bash
cat Makefile
```

to inspect the available targets.

---

## 14. Run the Application

From the project directory:

```bash
./build/medideliver
```

The application presents a console menu for operations such as:

```text
1. Select Customer
2. View Medicines
3. Search Medicine
4. Add Medicine to Cart
5. View Cart
6. Remove Medicine from Cart
7. Place Order
8. View Delivery Records
9. View Order History
10. Exit
```

The exact executable path is controlled by the project's Makefile.

---

## 15. Linux Kernel Module

The project contains a separate Linux kernel-module component:

```text
driver/
├── medideliver_driver.c
└── Makefile
```

The kernel module is intentionally kept separate from the user-space C++ application.

Conceptually:

```text
User Space
    |
    v
MediDeliver C++ Application
    |
    v
Linux Operating System
    |
    v
Kernel Space
    |
    v
MediDeliver Kernel Module
```

The Linux study material describes the kernel as the component responsible for hardware management and drivers. The project uses the kernel-module component to demonstrate this systems-programming layer.

### Build the Module

From the driver directory:

```bash
cd ~/MediDeliver/driver
make
```

The resulting kernel-module build artifacts are intentionally excluded from Git through `.gitignore`.

### Load the Module

Use the appropriate Linux module-loading command with administrator privileges:

```bash
sudo insmod medideliver_driver.ko
```

Check whether it is loaded:

```bash
lsmod | grep medideliver
```

Kernel messages can be inspected with:

```bash
dmesg | tail
```

### Unload the Module

```bash
sudo rmmod medideliver_driver
```

The exact module name should match the name produced by the driver Makefile.

---

## 16. Deployment Script

The project includes:

```text
deploy.sh
```

The script is provided to simplify project setup/build-related tasks.

Before running a shell script, ensure it has executable permission:

```bash
chmod +x deploy.sh
```

Then execute it according to the script's documented behavior.

---

## 17. Git and GitHub

Git is used to maintain the project's version history.

The training material describes the normal Git flow as:

```text
Working Directory
       |
       v
    git add
       |
       v
 Staging Area
       |
       v
  git commit
       |
       v
   Repository
```

Common project commands:

```bash
git status
git add .
git commit -m "Update project"
git log --oneline
git push
```

The repository is hosted on GitHub:

**ParagJena/MediDeliver**

The project history contains separate commits for major development stages such as the core system, persistence, kernel module, documentation and testing updates.

---

## 18. `.gitignore`

Generated build artifacts are not intended to be committed.

The `.gitignore` excludes files such as:

```text
driver/*.ko
driver/*.o
driver/*.mod
driver/*.mod.c
driver/Module.symvers
driver/modules.order
build/
backups/
```

This keeps the repository focused on source code, documentation, configuration and required project data.

---

## 19. Testing

The main functional workflow was tested through the console application.

Test areas include:

- Customer selection
- Medicine display
- Medicine search
- Cart insertion
- Cart removal
- Quantity validation
- Stock validation
- Order placement
- Payment processing
- Delivery creation
- Delivery queue processing
- Order history
- Delivery records
- File persistence

A successful test order produced corresponding order, payment and delivery records in the `data/` directory.

---

## 20. Architecture Perspective

The project also connects application software to the lower-level computer system model covered in the training.

```text
C++ Source Code
      |
      v
Compiler / Build Toolchain
      |
      v
Machine Instructions
      |
      v
CPU + Memory + I/O
      |
      v
Linux Operating System
      |
      v
Kernel / Drivers
```

The application is therefore not treated only as source code. It is compiled into executable instructions and executed through the Linux operating-system environment.

This follows the training principle:

**Software tells the computer what to do; architecture determines how the hardware performs it.**

---

## 21. Networking Scope

The current MediDeliver implementation is a local console application and uses file-based persistence. It does **not** currently implement a client-server network protocol or HTTP-based service.

Networking concepts from the training, such as application protocols, IP addressing, TCP/IP and troubleshooting, can be applied in a future networked version.

A future version could introduce:

```text
Client Application
        |
        v
Network / TCP-IP
        |
        v
Medicine Delivery Server
        |
        v
Database
```

This distinction is intentional: the current project demonstrates Linux and C++ concepts without claiming networking functionality that is not implemented.

---

## 22. Current Limitations

- File-based persistence is simpler than a production database.
- Payment processing is a simulation rather than a real payment gateway.
- Delivery tracking is represented by application records rather than live GPS tracking.
- The current application is console-based.
- The current implementation is local rather than client-server.
- Historical order loading is limited by the information stored in the order record format.

---

## 23. Future Enhancements

Possible extensions include:

- Database-backed persistence
- User authentication and authorization
- Real payment gateway integration
- Networked client-server architecture
- HTTP/REST API
- Real-time delivery tracking
- GUI or web interface
- Automated unit and integration testing
- More complete order-history reconstruction
- Network monitoring and troubleshooting support

---

## 24. Requirement Alignment

| Training / Project Requirement | MediDeliver Implementation |
|---|---|
| C++ | Core application is implemented in C++ |
| Linux | Developed and executed on Ubuntu/Linux |
| Data Structures | `vector`, `queue`, iterators |
| STL Algorithms | `std::sort` |
| OOP | Modular classes and encapsulation |
| Exception Handling | Standard C++ exceptions |
| File I/O | Text-based persistence |
| Build Tools | Makefile and compiler toolchain |
| Linux Driver Concepts | Separate kernel-module component |
| Software Architecture | Layered modular application flow |
| Git | Commit history and version control |
| GitHub | Complete project repository |
| Documentation | README, source organization and execution instructions |

---

## 25. Repository Quality

The repository is organized so that a reviewer can identify:

1. Application headers
2. Application source files
3. Driver source
4. Driver build configuration
5. Persistent data
6. Main build configuration
7. Deployment script
8. Documentation
9. Version-control configuration

Generated build artifacts are excluded from version control.

---

## 26. Conclusion

MediDeliver demonstrates a complete medicine-delivery workflow using C++ in a Linux environment.

The project brings together:

- Object-oriented C++ programming
- Data structures and STL
- Iterators and algorithms
- Exception handling
- File I/O and persistence
- Linux command-line development
- Build automation
- Linux kernel-module concepts
- Git version control
- GitHub-based project delivery

The implementation is intentionally modular so that each major business responsibility is represented by a dedicated class and can be explained independently during project evaluation.

---

## 27. Author

**Parag Jena**

**Project:** MediDeliver — Medicine Delivery Management System

**Platform:** Linux / Ubuntu

**Language:** C++

**Repository:** ParagJena/MediDeliver
