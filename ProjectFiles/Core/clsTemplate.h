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
  
    static map<string, T> LoadObjectsDataFromFiles(string fileName,
        function<T(string, string)> convertDateLineToObject,
        function<string(const T&)> getID) {


        map<string, T> mObjects;

        fstream filesDB;

        filesDB.open(fileName, ios::in);

        if (filesDB.is_open()) {
            string dataOfLine;

            while (getline(filesDB, dataOfLine)) {

                T object = convertDateLineToObject(dataOfLine, "#//#");
                mObjects[getID(object)] = object;

            }

            filesDB.close();
        }
        else {

            cout << "\nfile it is not open\n";
        }

        return mObjects;

    }

    static void  SaveObjectsDataToFile(string fileName, const map<string, T>& mObjects,
        function < enMode(const T&) > objectMode, function<string(const T&, string) > convertObjectToDataLine) {

        fstream fileDB;

        fileDB.open(fileName, ios::out);

        if (fileDB.is_open()) {


            for (const auto& object : mObjects) {


                if (objectMode(object.second) == enMode::eUpadateMode) {

                    fileDB << convertObjectToDataLine(object.second, "#//#") << "\n";
                }
            }

            fileDB.close();
        }



    }

    static string  GetEndNumberFromFile(function< map<string, T>() > loadObjectsDataFromFiles, short ConstIDNumbers = 5) {


        map<string, T> mObject = loadObjectsDataFromFiles();


        if (mObject.empty())
            return "1";

        auto mEndObject = mObject.rbegin();

        string WordId = mEndObject->first;


        string id = WordId.substr(ConstIDNumbers);



        return to_string(stoi(id) + 1);

    }

    static void UpdateObject(function< map<string, T>() > loadObjectsDataFromFiles,
                            T Object,
                            function<string(T)> getID,
                            function<void(const map<string, T>&)> saveObjectsDataToFile,
                            enIsSave& objectIsSave) {

        map < string, T> mObjects = loadObjectsDataFromFiles();

        mObjects[getID(Object)] = Object;

        saveObjectsDataToFile(mObjects);
        objectIsSave = enIsSave::DataisSaved;
    }


    static void AddObjectToFile(string fileName,
                                T object,
                                function<string(const T&, string)>convertObjectToDataLine,    
                                enIsSave& objectIsSave) {

        fstream fileDB;

        fileDB.open(fileName, ios::app);

        if (fileDB.is_open()) {


            fileDB << convertObjectToDataLine(object,"#//#") << endl;

        }

        fileDB.close();
        objectIsSave = enIsSave::DataisSaved;

    }

    static T FindObject(string objectID,    
                        function<map<string, T>()> loadObjectsDataFromFiles,
                        function<T()> getEmptyObject) {

        map < string, T> mObject = loadObjectsDataFromFiles();

        if (mObject.find(objectID) != mObject.end()) {


            return mObject[objectID];
        }
        return getEmptyObject();
    }

    static bool DeleteObject(T& object,
                            enMode& mode,
                            enIsSave& objectIsSave,
                            function<void()> UpdateObject,
                            function<T()>getEmptyObject) {

        mode = enMode::eEmptyMode;

        UpdateObject();

        if (objectIsSave == enIsSave::DataisSaved) {
            object = getEmptyObject();
            return true;
        }


        return false;

    }
    static bool Save(enMode& mode,  
                    function<void()> UpdateObject,
                    function<void()> AddNewObject,
                    enIsSave &objectIsSave) {

        switch (mode)
        {

        case enMode::eEmptyMode:
            return false;
            break;

        case enMode::eUpadateMode:

            UpdateObject();
            break;


        case enMode::eAddNewMode:

            mode = enMode::eUpadateMode;
            AddNewObject();

            break;


        }


        return (objectIsSave == enIsSave::DataisSaved);

    }

};

