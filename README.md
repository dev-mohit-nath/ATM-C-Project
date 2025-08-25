# 🏧 ATM Banking System (C Language)

A simple **ATM Simulation Project** written in C that allows users to:
- Register/Login using Account Number & PIN
- Check Balance
- Deposit Money
- Withdraw Money
- Update Account Balance (stored in a file)

This project demonstrates **file handling**, **structures**, and **menu-driven programming** in C.

---

## 📂 Project Structure

---

## 📖 Features

- ✅ User Login with Account Number & PIN  
- ✅ Check Account Balance  
- ✅ Deposit Money  
- ✅ Withdraw Money (with validation)  
- ✅ Balance Updates saved in `Account.txt`  
- ✅ Secure update using temporary file  

---

## 🗂️ Account File Format (`Account.txt`)

---

## 🖥️ Program Flow

### 1️⃣ Login Phase
The program reads each line from `Account.txt`:

```c
while(fscanf(fp, "%d,%49[^,],%d,%f\n",
             &user.accNo, user.name, &user.pin, &user.balance) == 4) {
    if(user.accNo == accNo && user.pin == pin) {
        found = 1;
        printf("✅ Login Successful\n");
        ATMmenu(user);
        break;
    }
}

==========================================
              ATM Main Menu
==========================================
Welcome, <UserName>
1. Check Balance
2. Deposit Money
3. Withdraw Money
4. Logout
