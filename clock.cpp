#include <iostream>

int main() {
    int hours_input = 0;
    int minutes_input = 0;
    int hours_output = 0;
    int minutes_check = 0;
    bool first_statement = false;
    bool second_statement = false;
    const int minutes_division = 10;
    const int half_of_day = 12;
    const int midnight = 0;
    const int zero_minutes = 0;
    const int full_day = 24;
    const int max_minutes = 60;
    const int morning_start = 6;
    const int evening_start = 18;
    const int name_one_limit = 1;
    const int name_two_limit = 4;
    const int special_names_exception_low = 11;
    const int special_names_exception_high = 14;

    std::cin >> hours_input;
    std::cin >> minutes_input;

    if (hours_input >= full_day || hours_input < zero_minutes || minutes_input >= max_minutes || minutes_input < zero_minutes) {
        std::cout << "введены недопустимые данные";
        return 0;
    }

    if (((hours_input == half_of_day) || (hours_input == midnight)) && (minutes_input == zero_minutes)) {
        switch (hours_input) {
            case midnight:
                std::cout << "полночь";
                break;

            case half_of_day:
                std::cout << "полдень";
                break;
        }
        return 0;
    }

    if (hours_input > half_of_day) {
        hours_output = hours_input - half_of_day;
    } else {
        hours_output = hours_input;
    }

    if (hours_output == name_one_limit) {
        std::cout << hours_output;
        std::cout << " час ";
    } else {
        if ((name_one_limit < hours_output) && (hours_output <= name_two_limit)) {
            std::cout << hours_output;
            std::cout << " часа ";
        } else {
            std::cout << hours_output;
            std::cout << " часов ";
        }
    }

    if (minutes_input != zero_minutes) {
        minutes_check = minutes_input % minutes_division;
        if ((minutes_check == name_one_limit) && (minutes_input != special_names_exception_low)) {
            std::cout << minutes_input;
            std::cout << " минута ";
        } else {
            first_statement = (name_one_limit < minutes_check) && (minutes_check <= name_two_limit);
            second_statement = (special_names_exception_low <= minutes_input) && (minutes_input <= special_names_exception_high);
            if (first_statement && !second_statement) {
                std::cout << minutes_input;
                std::cout << " минуты ";
            } else {
                std::cout << minutes_input;
                std::cout << " минут ";
            }
        }
    }

    if ((hours_input >= midnight) && (hours_input < morning_start)) {
        std::cout << "ночи";
    } else {
        if ((hours_input >= morning_start) && (hours_input < half_of_day)) {
            std::cout << "утра";
        } else {
            if (((hours_input >= half_of_day) && (hours_input < evening_start))) {
                std::cout << "дня";
            } else {
                std::cout << "вечера";
            }
        }
    }

    if (minutes_input == zero_minutes) {
        std::cout << " ровно";
    }
    return 0;
}
