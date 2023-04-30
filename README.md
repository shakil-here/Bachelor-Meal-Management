# Bachelor-Meal-Management



<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    
  </head>
  <body>
    <h1>Simple Spreadsheet-like Application in C</h1>
    <p>This is a C program that implements a simple spreadsheet-like application with various options for adding, removing, updating, and viewing member details, meal reports, bills, and meal costs.</p>
    <h2>Usage</h2>
    <ol>
      <li>Compile the program using a C compiler of your choice.</li>
      <li>Run the compiled executable file.</li>
      <li>Enter a filename to load sheet data from or start a new sheet.</li>
      <li>Select an option from the menu by entering its corresponding number.</li>
      <li>Follow the prompts for each selected option.</li>
      <li>To save the sheet data and exit, select option 11 and enter a filename to save the data to.</li>
    </ol>
    <h2>Options</h2>
    <p>The available options are:</p>
    <ol>
      <li>Add member: Creates a new `struct Member` object and adds it to the `sheet` object.</li>
      <li>Remove member: Removes a member from the `sheet` object.</li>
      <li>Update Meal: Updates the meal count of a member for a particular month.</li>
      <li>View Meal report: Prints a report of all member meal counts for a particular month.</li>
      <li>View member details: Prints details of a particular member.</li>
      <li>Add or cut Balance: Adds or subtracts a balance to/from a member's account.</li>
      <li>Add Bill: Creates a new `struct Bill` object and adds it to the `sheet` object.</li>
      <li>View Bill: Prints a report of all bills for a particular month.</li>
      <li>Add Meal Cost: Creates a new `struct MealCost` object and adds it to the `sheet` object.</li>
      <li>View Meal Cost Report: Prints a report of all meal costs for a particular month.</li>
      <li>Save and exit: Prompts the user to enter a filename to save the `sheet` object to, and then writes the contents of the `sheet` object to the specified file. The program then exits with a success code of 0.</li>
    </ol>
    <h2>License</h2>
    <p>This program is licensed under the MIT License. See the `LICENSE` file for details.</p>
  </body>
</html>
