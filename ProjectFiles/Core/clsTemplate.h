#pragma once
#include<iostream>
#include <functional>
#include"..//Database/FilesName.h"
using namespace std;
	
template <class T>
class clsTemplate
{


public:
    enum enMode {
        eUpadateMode = 1,
        eEmptyMode,
        eAddNewMode
    };

    enum enIsSave {
        DataisSaved = 1,
        DataisUnSaved
    };
  
    static map<string, T> LoadFromFiles(string fileName, function<T(string)> functionConvertDateToLine, function<string(T)> getID){

       
        map<string, T> mObject;

        fstream fileOfDoctor;




        fileOfDoctor.open(fileName, ios::in);

        if (fileOfDoctor.is_open()) {
        string dataOfLine;

            while (getline(fileOfDoctor, dataOfLine)) {



                T object = functionConvertDateToLine(dataOfLine);


                mObject[getID(object)] = object;

            }

            fileOfDoctor.close();
        }
        else {

            cout << "\nfile it is not open\n";
        }

        return mObject;

    }

    static void  SaveDataToFile(string fileName, const map<string, T>& ObjectDataMap, function < enMode  (const T&) > Mode,function<string ( const T&) > convertObjectToDataLine ) {

        fstream fileOfDoctor;



        fileOfDoctor.open(fileName, ios::out);

        if (fileOfDoctor.is_open()) {


            for (const auto& D : ObjectDataMap) {


                if (Mode(D.second) == enMode::eUpadateMode) {

                    fileOfDoctor << convertObjectToDataLine(D.second) << "\n";
                }
            }

            fileOfDoctor.close();
        }
      





    }

    static string  GetEndNumberFromFile(function< map<string ,T> () > LoadsFromFiles) {


        map<string, T> mObject = LoadsFromFiles();


        if (mObject.empty())
            return "1";

        auto mEndObject = mObject.rbegin();

        string WordId = mEndObject->first;


        string id = WordId.substr(5);



        return to_string(stoi(id) + 1);

    }
   static void UpdateObject(function< map<string,T>() > loadsFromFiles ,T Object, function<string (T)> getID, function<void (const map<string,T> &)> saveToFile,enIsSave &objectIsSave) {

        map < string, T> mObjects = loadsFromFiles();

        mObjects[getID(Object)] = Object;

        saveToFile(mObjects);
        objectIsSave = enIsSave::DataisSaved;
    }
  static void AddObjectToFile(string fileName,T object ,function<string(T)>convertObjectToDataLine,enIsSave &objectIsSave) {

       fstream fileOfObject;

       fileOfObject.open(fileName, ios::app);

       if (fileOfObject.is_open()) {

 
           fileOfObject << convertObjectToDataLine(object) << endl;

       }

       fileOfObject.close();
       objectIsSave = enIsSave::DataisSaved;

   }
  static T FindObject(string objectID,function<map<string,T> ()>loadsFromFiles,function<T ()> getEmptyObject) {

      map < string, T> mObject = loadsFromFiles();

      if (mObject.find(objectID) != mObject.end()) {


          return mObject[objectID];
      }
      return getEmptyObject();
  }

   static bool DeleteObject(T &object,enMode &mode,enIsSave &objectIsSave, function<void()> UpdateObject, function<T()>getEmptyObject) {

     mode = enMode::eEmptyMode;

     UpdateObject();

      if (objectIsSave == enIsSave::DataisSaved)
          object = getEmptyObject();

      return true;

      return false;

  }
};

