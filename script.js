document.getElementById('calculateFare').addEventListener('click', function () {
    const pickup = document.getElementById('pickup').value.trim();
    const destination = document.getElementById('destination').value.trim();
    const vehicleType = document.getElementById('vehicleType').value;

    if (!pickup || !destination) {
        alert("Please enter both pickup and destination locations.");
        return;
    }

    // Simulate distance calculation (e.g., in kilometers)
    const distance = Math.random() * (15 - 2) + 2; // Random distance between 2 and 15 km

    // Fare rates in INR
    const rates = {
        car: 10,  // ₹10 per km
        bike: 5,  // ₹5 per km
        auto: 8,  // ₹8 per km
    };

    const fare = (distance * rates[vehicleType]).toFixed(2);

    // Display result
    document.getElementById('fareResult').innerHTML = `
        <p><strong>Pickup:</strong> ${pickup}</p>
        <p><strong>Destination:</strong> ${destination}</p>
        <p><strong>Vehicle Type:</strong> ${vehicleType.charAt(0).toUpperCase() + vehicleType.slice(1)}</p>
        <p><strong>Estimated Distance:</strong> ${distance.toFixed(2)} km</p>
        <p><strong>Fare Estimate:</strong> ₹${fare}</p>
    `;
});
