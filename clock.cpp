#include <iostream>

namespace {
const int kDecimalBase = 10;

const int kTwelveHoursFormatBase = 12;

const int kMidnight = 0;
const int kHalfOfDay = 12;

const int kMinimumMinutes = 0;
const int kMaximumMinutes = 59;
const int kMinimumHours = 0;
const int kMaximumHours = 23;

const int kNightBegin = 0;
const int kNightEnd = 4;
const int kMorningBegin = 5;
const int kMorningEnd = 11;
const int kDayBegin = 12;
const int kDayEnd = 17;
const int kEveningBegin = 18;
const int kEveningEnd = 23;

const int kNominativeSingularMinutes = 1;
const int kGenitiveSingularMinutesLowerBoundary = 2;
const int kGenitiveSingularMinutesUpperBoundary = 4;
const int kGenitivePlularMinutesLowerBoundary = 11;
const int kGenitivePlularMinutesUpperBoundary = 14;

const int kNominativeSingularHours = 1;
const int kGenitiveSingularHoursLowerBoundary = 2;
const int kGenitiveSingularHoursUpperBoundary = 4;
}  // namespace

int main(int, char**) {
    int hours = 0;
    int minutes = 0;

    std::cout << "Введите время в формате *Часы Минуты* при помощи цифр. (0 <= Часы < 24, 0 <= Минуты < 60)\n";
    std::cin >> hours >> minutes;

    if (hours < kMinimumHours || hours > kMaximumHours || minutes < kMinimumMinutes || minutes > kMaximumMinutes || std::cin.fail()) {
        std::cout << "Введены недопустимые данные\n";
        return 1;
    }

    if ((hours == kHalfOfDay) && (minutes == kMinimumMinutes)) {
        std::cout << "Полдень\n";
        return 0;
    } else if ((hours == kMidnight) && (minutes == kMinimumMinutes)) {
        std::cout << "Полночь\n";
        return 0;
    }

    int hoursIn12HoursFormat = (hours > kTwelveHoursFormatBase) ? (hours - kTwelveHoursFormatBase) : hours;

    std::cout << hoursIn12HoursFormat;
    if (hoursIn12HoursFormat == kNominativeSingularHours) {
        std::cout << " час";
    } else if ((hoursIn12HoursFormat >= kGenitiveSingularHoursLowerBoundary) && (hoursIn12HoursFormat <= kGenitiveSingularHoursUpperBoundary)) {
        std::cout << " часа";
    } else {
        std::cout << " часов";
    }

    if (minutes != kMinimumMinutes) {
        int lastDigitMinutes = minutes % kDecimalBase;
        std::cout << ' ' << minutes;
        if (lastDigitMinutes == kNominativeSingularMinutes && minutes != kGenitivePlularMinutesLowerBoundary) {
            std::cout << " минута";
        } else if ((lastDigitMinutes >= kGenitiveSingularMinutesLowerBoundary) && (lastDigitMinutes <= kGenitiveSingularMinutesUpperBoundary) &&
                   (minutes < kGenitivePlularMinutesLowerBoundary || minutes > kGenitivePlularMinutesUpperBoundary)) {
            std::cout << " минуты";
        } else {
            std::cout << " минут";
        }
    }

    if ((hours >= kNightBegin) && (hours <= kNightEnd)) {
        std::cout << " ночи";
    } else if ((hours >= kMorningBegin) && (hours <= kMorningEnd)) {
        std::cout << " утра";
    } else if ((hours >= kDayBegin) && (hours <= kDayEnd)) {
        std::cout << " дня";
    } else if ((hours >= kEveningBegin) && (hours <= kEveningEnd)) {
        std::cout << " вечера";
    }

    if (minutes == kMinimumMinutes) {
        std::cout << " ровно";
    }
    std::cout << '\n';
    return 0;
}
