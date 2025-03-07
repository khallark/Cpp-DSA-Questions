const nodemailer = require("nodemailer");

// Create transporter
let transporter = nodemailer.createTransport({
    service: "gmail",
    auth: {
        user: "khallark295@gmail.com",
        pass: "your_app_password"
    }
});

// Email details
let mailOptions = {
    from: "your_email@gmail.com",
    to: "recipient_email@example.com",
    subject: "Test Email",
    text: "This is a test email from Node.js!"
};

// Send email
transporter.sendMail(mailOptions, (error, info) => {
    if (error) {
        console.log("Error: ", error);
    } else {
        console.log("Email sent: " + info.response);
    }
});
