#include "datetime.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;
/**
 * Models a timestamp in format YYYY-MM-DD HH:MM:SS 
 */
  /**
   * Default constructor for current system time/date
   */
  DateTime::DateTime()
  {
      // this returns the raw current time and date
      time_t rawtime;
      struct tm * timeinfo;

      time(&rawtime);
      timeinfo = localtime(&rawtime);
    
      year_ = timeinfo->tm_year + 1900;
      month_ = timeinfo->tm_mon + 1;
      day_ = timeinfo->tm_mday;

      hour_ = timeinfo->tm_hour;
      min_ = timeinfo->tm_min;
      sec_ = timeinfo->tm_sec;
  }

  /**
   * Alternative constructor 
   */
  DateTime::DateTime(int hh, int mm, int ss, int year, int month, int day)
  {
      hour_ = hh;
      min_ = mm;
      sec_ = ss;
      year_ = year;
      month_ = month;
      day_ = day;
  }

  /**
   * Return true if the timestamp is less-than other's
   *
   * @return result of less-than comparison of timestamp
   */
  bool DateTime::operator<(const DateTime& other) const
  {
      // compares the years
        if (this->year_ < other.year_) // year is less than other
            return true; // true
        else if (this->year_ > other.year_) // if year is greater than or equal to other
            return false;

        // compares month if year is same
        if (this->month_ < other.month_) // month is less than other
            return true; // true
        else if (this->month_ > other.month_) // if year is greater than or equal to other
            return false;
        
        // compares day if month is same
        if (this->day_ < other.day_) // day is less than other
            return true; // true
        else if (this->day_ > other.day_) // if day is greater than or equal to other
            return false;
        
        // compares hour if day is same
        if (this->hour_ < other.hour_) // hour is less than other
            return true; // true
        else if (this->hour_ > other.hour_) // if hour is greater than or equal to other
            return false;
        
        // compares mins if hour is same
        if (this->min_ < other.min_) // min is less than other
            return true; // true
        else if (this->min_ > other.min_) // if min is greater than or equal to other
            return false;

        // compares secs if mins is same
        if (this->sec_ < other.sec_) // sec is less than other
            return true; // true
        else if (this->sec_ > other.sec_) // if sec is greater than or equal to other
            return false;   

        return false;
    
  }

  /**
   * Outputs the timestamp to the given ostream in format:
   *   YYYY-MM-DD HH::MM::SS
   *
   * @return the ostream passed in as an argument
   */
  ostream& operator<<(ostream& os, const DateTime& other)
  {

      string timestamp;
      os << other.year_;
      os << "-";

      if (other.month_ < 10)
        os << "0";
      os << other.month_;
      os << "-";

      if (other.day_ < 10)
      os << "0";
      os << other.day_;
      os << " ";

      if (other.hour_ < 10)
        os << "0";
      os << other.hour_;
      os << ":";

      if (other.min_ < 10)
        os << "0";
      os << other.min_;
      os << ":";

      if (other.sec_ < 10)
        os << "0";
      os << other.sec_;
      // cout << timestamp << endl;
      //os << timestamp;
      return os;
  }

  /**
   * Inputs the timestamp to the given istream expecting the format:
   *   YYYY-MM-DD HH::MM::SS
   *  Returns if an error in the format with the DateTime set to the
   *   current system time/date
   *   
   *
   * @return the istream passed in as an argument
   */
  istream& operator>>(istream& is, DateTime& dt)
  {
      // must parse through the line to separate ints and strings
      string date;
      int year; int month; int day; 
      int hour; int min; int sec;
      // getting year
      getline(is, date, '-');
      stringstream ss(date);
      ss >> year;
      // getting month
      getline(is, date, '-');
      stringstream ss1(date);
      ss1 >> month;
      // getting day
      getline(is, date, ' ');
      stringstream ss2(date);
      ss2 >> day;
      // getting hour
      getline(is, date, ':');
      stringstream ss3(date);
      ss3 >> hour;
      // getting min
      getline(is, date, ':');
      stringstream ss4(date);
      ss4 >> min;
      // getting sec
      getline(is, date);
      stringstream ss5(date);
      ss5 >> sec;

      dt = DateTime(hour, min, sec, year, month, day);
      return is;
  }
