# PassGaurd 🔐

**PassGaurd** is a local password management application designed for learning and educational purposes. It allows users to securely register, encrypt, and manage their passwords using a simple Caesar cipher algorithm, all through a user-friendly GUI built with C and raylib.

![PassGaurd Banner](./githubAssets/banner.jpg)

---

## 🌟 Features

- **Secure User Registration**: Register users with validated usernames and encrypted passwords
- **Password Encryption**: All passwords stored using Caesar Cipher (educational focus)
- **User Authentication**: Secure login using encrypted password verification
- **Persistent Storage**: User data saved and loaded from a local file (`users.dat`)
- **User Management**: Register, login, view, search, and sort user accounts
- **Input Validation**: Enforces minimum password length and prevents invalid entries
- **Interactive GUI**: Clean, user-friendly graphical interface powered by raylib
- **Status & Feedback Messages**: Real-time success/error messages for actions
- **Simple Sorting & Searching**: Organize and find users easily with built-in algorithms

---

## 🚀 Technologies Used

- **C (ISO C99)** – Core logic, password encryption and user management
- **raylib** – Lightweight C graphics library for GUI and easy rendering
- **Standard C File I/O** – Save and load user data for persistence
- **GCC/Clang** – Compiler support for building on any major OS
- **Makefile** – Simplified build and execution

---

## 📁 Project Structure

```
VenturaFund/
├── index.html # Homepage
├── signIn.html # Sign-in page
├── signUp.html # Registration page
├── script.js # Javascript
├── discover.html # Main Campaigns Page
├── donation.html # Universal donation page
├── formDetails.js # Form Validation Javascript
├── styles.css # Main stylesheet
├── images/ # Image assets
│   ├── ArtSupplies.jpg
│   ├── Cancer.jpg
│   ├── Business.jpg
│   ├── Emergency.jpg
│   ├── Dialysis.jpg
│   └── EarthquakeRelief.jpg
│   └── EcoCafe.jpg
│   └── Educational Featured.jpg
│   └── Educational.jpg
│   └── FireRelief.jpg
│   └── FloodRelief.jpg
│   └── Heart.jpg
│   └── Hero.jpg
│   └── JewelryWorkshop.jpg
│   └── Medical Featured.jpg
│   └── Medical.jpg
│   └── MobileBakery.jpg
│   └── RescueSupport.jpg
│   └── Sarah.jpg
│   └── Schoralship.jpg
│   └── STEMLAB.jpg
│   └── TechStartup.jpg
├── categories/
│   ├── medical/
│   │   ├── medicalCampaigns.html
│   │   └── campaigns/
│   │       ├── Cancer.html
│   │       ├── Dialysis.html
│   │       ├── Heart.html
│   │       └── Sarah.html
│   ├── educational/
│   │   ├── educationalCampaigns.html
│   │   └── campaigns/
│   │       ├── SchoolLibrary.html
│   │       ├── STEMLab.html
│   │       ├── Scholarship.html
│   │       └── ArtSupplies.html
│   ├── business/
│   │   ├── businessCampaigns.html
│   │   └── campaigns/
│   │       ├── EcoCafe.html
│   │       ├── MobileBakery.html
│   │       ├── TechStartup.html
│   │       └── JewelryWorkshop.html
│   └── emergency/
│       ├── emergencyCampaigns.html
│       └── campaigns/
│           ├── FloodRelief.html
│           ├── FireRelief.html
│           ├── EarthquakeRelief.html
│           └── RescueSupport.html
└── start-a-campaign/
    ├── startCampaign.html
    ├── storyMedia.html
    └── reviewLaunch.html
```

---

## 🛠️ Installation & Setup

### Prerequisites
- GCC or compatible C compiler
- raylib library installed on your system

### Steps

1. **Clone the repository**

```
git clone https://github.com/YourUsername/PassGuard.git
cd PassGuard
```


2. **Compile the project**

```
gcc main.c -o passguard -lraylib -lm -lpthread -ldl -lrt -lX11
```
*(Adjust compile flags if required for your OS and raylib version.)*


3. **Run the application**

```
./passguard
```


---

## 🎨 Customization

### Colors & UI
- Edit color themes and UI components directly in the `main.c` file or your raylib settings.

### Adjusting Password Settings
- Change encryption key, minimum password length, or validation requirements by modifying constants at the top of `main.c`:  
    ```
    #define ENCRYPTION_KEY 5
    #define MIN_PASSWORD_LENGTH 6
    ```

### Adding Users (for testing)
- Run the application, use the 'Register' feature, and input unique usernames and passwords that meet criteria.


## 🔮 Future Enhancements

- Database integration (SQLite, MySQL) for large-scale user storage  
- Backend integration (Node.js, Python, etc.) for multi-user support  
- Advanced encryption (bcrypt, Argon2, SHA-256) for stronger password protection  
- Web or mobile app (React Native / Flutter) – build for Android/iOS devices  
- Multi-factor authentication (MFA) for increased security  
- User authorization levels (e.g., admin tools)  
- Password strength meter and checker  
- Password generator for secure random passwords  
- Activity logging and audit trails for user actions  
- Session management and automatic logout  
- Email notifications (for registration, password changes, account activity)  
- UI enhancements: modern design, light/dark theme  
- Import/export password database (CSV/JSON backup)  
- Cloud sync for cross-device password management  
- Accessibility and localization (multi-language support)  
- Integration with browser extensions or autofill services  

---

## 👀 Quick Peek

### Main Menu Screen
![Main Menu](./githubAssets/Main%20Menu.png)

### User Registration Screen
![User Registration](./githubAssets/userRegistration.gif)

### User Login Screen
![User Login](./githubAssets/userLogin.gif)

### View Users Screen
![View Users](./githubAssets/viewUsers.png)

### Search Users Screen
![Search Users](./githubAssets/searchUsers.gif)

### Error Message
![Error Message](./githubAssets/errorMessage.gif)

### Save & Load Users Screen
![Save & Load Users](./githubAssets/saveloadUsers.gif)

---

## 🤝 Contributing

Currently not accepting contributions (college project).  
Feel free to clone the repo and experiment.

---

## 📄 License

This project is licensed under the MIT License.  
See the [LICENSE](LICENSE) file.

---

## 👥 Authors

- **Ronel Abraham Mathew** – Landing Page, Start a Campaign Page & UI/UX  
  GitHub: [RM1338](https://github.com/RM1338)  
  LinkedIn: [Ronel Abraham Mathew](https://linkedin.com/in/ronelm)

- **Joshua Sibichan Scariya** – Sign In/Up, Business & Emergency Pages, Interactive JS  
  GitHub: [BuildwJoshh](https://github.com/BuildwJoshh)  
  LinkedIn: [Joshua Sibichan Scariya](https://www.linkedin.com/in/joshua-sibichan-scariya-141488380/)

- **Aditilakshmanan** – Medical & Educational Pages  
  GitHub: [BuildwJoshh](https://github.com/)  
  LinkedIn: [](https://www.linkedin.com/in//)

- **Yogesh** – Research & Donation Page  
  GitHub: [Yogesh](https://github.com/)  
  LinkedIn: [Yogesh](https://linkedin.com/in/)

---

## 📞 Contact

**Ronel Abraham Mathew**  
Email: rma80070@gmail.com  
GitHub: [RM1338](https://github.com/RM1338)  
LinkedIn: [Ronel Abraham Mathew](https://linkedin.com/in/ronelm)

**Joshua Sibichan Scariya**  
Email: joshuasibichan7@gmail.com  
GitHub: [BuildwJoshh](https://github.com/BuildwJoshh)  
LinkedIn: [Joshua Sibichan Scariya](https://linkedin.com/in/joshua-sibichan-scariya-141488380/)  

**Aditilakshmanan**  
Email:   
GitHub: [](https://github.com/)  
LinkedIn: [](https://www.linkedin.com/in//)

**Yogesh**  
Email: yogesh@gmail.com  
GitHub: [Yogesh](https://github.com/SarveshAK7786)  
LinkedIn: [Yogesh](https://linkedin.com/in/sarvesh-a-b27010377)

---

## ⭐ Show Your Support

Give a ⭐️ if this project helped you!

---

Made with ❤️ by the CodeGen Team