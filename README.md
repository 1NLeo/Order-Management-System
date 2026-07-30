# Order Management System

A console-based **Order Management System** written in C, developed as a learning project to practice structs, pointers, and entity relationships in a real-world scenario.

## 📋 Overview

This system manages **customers**, **products**, and **orders**, correctly linking these entities together: each order belongs to a customer and contains one or more products with their respective quantities. The total value of each order is calculated automatically based on product prices and quantities.

This project was built as part of my ongoing studies in C programming, with a focus on understanding how structs and pointers can be combined to model relationships between different pieces of data — a step up from simpler single-entity projects.

## ✨ Features

- **Customer registration** — name, CPF, and unique ID
- **Product registration** — name, price, and unique ID
- **Order creation**
  - Validates that the customer exists before creating the order
  - Allows adding multiple products with their quantities
  - Validates that each product exists
  - Automatically calculates the order's total value
  - Stores the order date
- **Reports**
  - List all registered customers and products
  - List all orders with customer name, date, total value, and a detailed breakdown of purchased items

## 🗂️ Data Structures

| Struct | Fields |
|---|---|
| `Customer` | `id`, `name`, `cpf` |
| `Product` | `id`, `name`, `price` |
| `OrderItem` | `productId`, `quantity` |
| `Order` | `orderNumber`, `customerId`, `items[]`, `itemCount`, `totalValue`, `date` |

## 🛠️ Built With

- **Language:** C
- **Concepts applied:** structs, pointers, arrays, input validation, modular functions

## 🚀 How to Run

```bash
gcc main.c -o orderflow
./orderflow
```

## 📖 Menu

```
=====================
|       MENU        |
=====================
| [1] Registrations |
| [2] Orders        |
| [3] Reports       |
| [4] Exit          |
=====================
```

Each option leads to a submenu:

- **Registrations** → Register Customer, Register Product
- **Orders** → Create New Order
- **Reports** → List Customers and Products, List Orders

## 🎯 Motivation

This project is part of my portfolio while preparing my application to the **Apple Developer Academy**. It builds on a previous project (a bus ticket reservation system) by introducing a three-way relationship between entities instead of just two, along with automatic value calculations.

## 📌 Status

🚧 In development

## 📄 License

This project is open source and available for study purposes.
