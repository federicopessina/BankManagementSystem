#include "AccountType.h"

/// <summary>
/// Get the account type from the user
/// </summary>
/// <returns>Savings amount</returns>
char AccountType::get_saving()
{
    return saving;
}

/// <summary>
/// Get the account type from the user
/// </summary>
/// <returns>Account type</returns>
char AccountType::get_current()
{
    return current;
}
