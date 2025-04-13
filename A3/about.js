document.addEventListener("DOMContentLoaded", function () {
    const menuButton = document.getElementById("but");
    const menu = document.getElementById("menu");

    menuButton.addEventListener("click", function () {
        // Toggle visibility
        if (menu.classList.contains("hidden")) {
            menu.classList.remove("hidden");
        } else {
            menu.classList.add("hidden");
        }
    });
});
