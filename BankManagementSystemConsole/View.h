#pragma once
class View
{
public:
	/// <summary>
	/// Clear the Console Window from previous text.
	/// </summary>
	static void clear_console();
	/// <summary>
	/// Print to the user the welcome message in the Console Window.
	/// </summary>
	static void print_intro();
	/// <summary>
	/// Print to the user the menu message in the Console Window.
	/// </summary>
	static void print_menu();
	/// <summary>
	/// Print to the user greetings for using the app.
	/// </summary>
	static void print_greetings();
};

