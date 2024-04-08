var Mailer = require("nodemailer");

// Initialize the Authentication of Gmail Options
var transportar = Mailer.createTransport({
  service: "gmail",
  auth: {
    user: "stralezl06@gmail.com", // Your Gmail ID
    pass: "kquxqkmgafialzmw",         // Your Gmail Password
  },
});

// Deifne mailing options like Sender Email and Receiver.
var mailOptions = {
  from: "stralezl06@gmail.com", // Sender ID
  to: "zlatanovichs6@gmail.com", // Reciever ID
  subject: "Email Subjects", // Mail Subject
  html: "<h1>Welcome Reciver</h1><p>That was easy!</p>", // Description
};

// Send an Email
transportar.sendMail(mailOptions, (error, info) => {
  if (error) console.log(error);
  console.log(info);
});