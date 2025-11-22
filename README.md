# PassGaurd 🔐

**PassGaurd** is a multi-category crowdfunding platform that enables users to create and support campaigns across various causes including Medical, Educational, Business and Emergency needs.

![PassGaurd Banner](./githubAssets/banner.jpg)

---

## 🌟 Features

- **Multi-Category Support**: Medical, Educational, Business and Emergency campaigns
- **Campaign Management**: Create, browse, and support campaigns with detailed progress tracking
- **Secure Donations**: Integrated payment gateway support (ready for Stripe, PayPal, Razorpay)
- **Responsive Design**: Built with Bootstrap 5 for mobile-first, responsive layouts
- **Milestone-Based Funding**: Transparent fund release based on campaign milestones
- **User Authentication**: Sign-in and registration system
- **Campaign Discovery**: Browse trending and featured campaigns
- **Individual Campaign Pages**: Detailed pages with updates, donations, and organizer info

---

## 🚀 Technologies Used

- **HTML5** - Structure and semantic markup
- **CSS3** - Custom styling and animations
- **Bootstrap 5.3.2** - Responsive grid system and components
- **Font Awesome 6.4.0** - Icons and visual elements
- **Google Fonts (Inter)** - Modern, clean typography
- **JavaScript** - Form handling and interactivity (ready for enhancement)

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
- A modern web browser (Chrome, Firefox, Safari, Edge)
- A local web server (optional, for testing)

### Steps

1. **Clone the repository**

```
git clone https://github.com/RM1338/VenturaFund.git
cd VenturaFund
```

2. **Open in browser**
- Simply open `index.html` in your browser  
- Or use a local server:

Using Python:
```
python -m http.server 8000
```

Using Node.js:
```
npx http-server
```

3. **Access the site**

Visit:  
`http://localhost:8000`

---

## 🎨 Customization

### Colors
Customize in `styles.css`:

```css
:root {
  --primary-color: #2ecc71;
  --secondary-color: #27ae60;
}
```

### Adding New Campaigns
1. Create a new HTML file in the appropriate `campaigns/` folder  
2. Follow the existing campaign template structure  
3. Update the category listing page to link to your new campaign  

---

## 🔮 Future Enhancements

- Backend integration (Node.js/PHP/Python)
- Database integration (MongoDB/MySQL)
- Payment gateway integration (Stripe, PayPal, Razorpay)
- User authentication and authorization
- Campaign analytics dashboard
- Real-time donation tracking
- Email notifications
- Social media sharing integration
- Campaign comments and Q&A section
- Advanced search and filtering
- Mobile app (React Native/Flutter)

---

## 👀 Quick Peek

### Homepage
![Homepage]()

### Campaign Listing
![Campaign Listing]()

### Donation Page
![Donation Page]()

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
  GitHub: [gavriel953](https://github.com/BuildwJoshh)  
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