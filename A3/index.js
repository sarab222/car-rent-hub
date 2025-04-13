// 1. Toggle mobile menu
function toggleMenu() {
    var menu = document.getElementById("menu");
    if (menu.classList.contains("hidden")) {
      menu.classList.remove("hidden");
    } else {
      menu.classList.add("hidden");
    }
  }
  
  // 2. Show search alert
  function searchCars() {
    alert("Searching for available cars...");
  }
  
  // 3. Show welcome message
  function welcomeUser() {
    alert("Welcome to the Car Rental System!");
  }
  
  // 4. Highlight selected button (like Cars)
  function selectVehicleType() {
    alert("You selected Cars!");
  }
  
  // 5. Validate pickup and return dates
  function checkDates() {
    var pickup = document.querySelectorAll("input[type='date']")[0].value;
    var dropoff = document.querySelectorAll("input[type='date']")[1].value;
    if (pickup && dropoff && pickup > dropoff) {
      alert("Return date cannot be before pickup date.");
    }
  }
  
  // 6. Show checkbox status
  function checkNegotiatedRate() {
    var checkbox = document.querySelector("input[type='checkbox']");
    if (checkbox.checked) {
      alert("Negotiated rate selected.");
    } else {
      alert("Negotiated rate not selected.");
    }
  }
  
  // 7. Print all form inputs in console
  function printFormValues() {
    var inputs = document.querySelectorAll("input, select");
    for (var i = 0; i < inputs.length; i++) {
      console.log(inputs[i].value);
    }
  }
  
  // 8. Clear all form inputs
  function clearForm() {
    var inputs = document.querySelectorAll("input, select");
    for (var i = 0; i < inputs.length; i++) {
      if (inputs[i].type === "checkbox") {
        inputs[i].checked = false;
      } else {
        inputs[i].value = "";
      }
    }
    alert("Form cleared!");
  }
  
  // 9. Show car info when Rent Now is clicked
  function rentCar(model) {
    alert("You selected to rent: " + model);
  }
  
  // 10. Show thank you message
  function showThanks() {
    alert("Thank you for using Car Rental!");
  }
  
  // Event setup
  document.addEventListener("DOMContentLoaded", function () {
    document.getElementById("but").addEventListener("click", toggleMenu);
    welcomeUser();
  });
  
