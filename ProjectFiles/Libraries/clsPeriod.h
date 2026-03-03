#pragma once
#include "clsDate.h"
class clsPeriod {

private:
	clsDate _StartDate;
	clsDate _EndDate;
public:

    clsPeriod() {

    }
    clsPeriod(const clsPeriod& copyPeriod) {
        _StartDate = copyPeriod._StartDate;
        _EndDate = copyPeriod._EndDate;
    }
    clsPeriod(clsDate Date1, clsDate Date2) {
        _StartDate = Date1;
        _EndDate = Date2;
    }


    static bool IsOverlapPeriods(clsPeriod FirstPeriod, clsPeriod SecondPeriod)
    {

        return !(
            clsDate::CompareDates(SecondPeriod._StartDate, FirstPeriod._EndDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(SecondPeriod._StartDate, FirstPeriod._EndDate) == clsDate::enDateCompare::After
            );
    }
    bool IsOverlapPeriods(clsPeriod SecondPeriod) {
        return IsOverlapPeriods(*this, SecondPeriod);
    }

    static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDate)
    {
        return clsDate::GetDifferenceInDays(Period._StartDate, Period._EndDate,
            IncludeEndDate);
    }
    int PeriodLengthInDays(bool IncludeEndDate) {
        return PeriodLengthInDays(*this, IncludeEndDate);
    }

    static bool isDateInPeriod(clsDate Date, clsPeriod Period)
    {
        return !(clsDate::CompareDates(Date, Period._StartDate) == clsDate::enDateCompare::Before
            ||
            clsDate::CompareDates(Date, Period._EndDate) == clsDate::enDateCompare::After);
    }
    bool isDateInPeriod(clsDate Date) {
        return isDateInPeriod(Date, *this);
    }

    static int CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
    {
        int Period1Length = PeriodLengthInDays(Period1, true);
        int Period2Length = PeriodLengthInDays(Period2, true);
        int OverlapDays = 0;

        if (!IsOverlapPeriods(Period1, Period2))
            return 0;

        if (Period1Length < Period2Length)
        {
            while (clsDate::IsDate1BeforeDate2(Period1._StartDate, Period1._EndDate))
            {
                if (isDateInPeriod(Period1._StartDate, Period2))
                    OverlapDays++;

                Period1._StartDate = clsDate::IncreaseDateByOneDay(Period1._StartDate);
            }
        }
        else
        {
            while (clsDate::IsDate1BeforeDate2(Period2._StartDate, Period2._EndDate))
            {
                if (isDateInPeriod(Period2._StartDate, Period1))
                    OverlapDays++;

                Period2._StartDate = clsDate::IncreaseDateByOneDay(Period2._StartDate);
            }
        }
        return OverlapDays;
    }
    int CountOverlapDays(clsPeriod SecondPeriod) {
        return CountOverlapDays(*this, SecondPeriod);
    }
};

