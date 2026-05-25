#pragma once
#include<string>
using namespace std;
class clsPermissions {

public:
    enum enClinicRole
    {
        eUnknownRole = 0,
        eSuperAdmin,
        eAdmin,
        eReceptionist,
    };
    enum enUserPermissionsOption
    {
        eManagePatientsMenu = 1,
        eShowAllPatients = 4,
        eUpdatePatient = 7,
        eFindPatient = 10,

        eManageDoctorsMenu = 13,
        eShowAllDoctors = 16,
        eAddNewDoctor = 19,
        eUpdateDoctor = 22,
        eDeleteDoctor = 25,
        eFindDoctor = 28,
        eUpdateDoctorsSpecialization = 31,
        eUpdateDoctorsFeesRate = 34,

        eManageUsersMenu = 37,
        eShowAllUsers = 40,
        eAddNewUser = 43,
        eUpdateUser = 46,
        eDeleteUser = 49,
        eFindUser = 52,
        eUpdateUsersPermissions = 55,

        eManageAppointmentsMenu = 58,
        eShowAllAppointments = 61,
        eAddNewAppointment = 64,
        eUpdateAppointment = 67,
        eDeleteAppointment = 70,
        eFindAppointment = 73
    };
private:
 
    enClinicRole _role;
    int _permissions;

    int _GetAdminPermissions() {
        return (int)enUserPermissionsOption::eManagePatientsMenu + enUserPermissionsOption::eShowAllPatients +
            enUserPermissionsOption::eUpdatePatient + enUserPermissionsOption::eFindPatient +
            enUserPermissionsOption::eManageDoctorsMenu + enUserPermissionsOption::eShowAllDoctors +
            enUserPermissionsOption::eUpdateDoctor + enUserPermissionsOption::eFindDoctor + enUserPermissionsOption::eManageUsersMenu +
            enUserPermissionsOption::eShowAllUsers + enUserPermissionsOption::eAddNewUser + enUserPermissionsOption::eUpdateUser +
            enUserPermissionsOption::eFindUser + enUserPermissionsOption::eManageAppointmentsMenu +
            enUserPermissionsOption::eShowAllAppointments + enUserPermissionsOption::eAddNewAppointment +
            enUserPermissionsOption::eUpdateAppointment + enUserPermissionsOption::eDeleteAppointment +
            enUserPermissionsOption::eFindAppointment;

    }
    int _GetReceptionistPermissions() {
        return (int)enUserPermissionsOption::eManagePatientsMenu + enUserPermissionsOption::eShowAllPatients +
            enUserPermissionsOption::eUpdatePatient + enUserPermissionsOption::eFindPatient +
            enUserPermissionsOption::eManageDoctorsMenu + enUserPermissionsOption::eShowAllDoctors +
            enUserPermissionsOption::eFindDoctor + enUserPermissionsOption::eManageUsersMenu +
            enUserPermissionsOption::eManageAppointmentsMenu + enUserPermissionsOption::eShowAllAppointments +
            enUserPermissionsOption::eAddNewAppointment + enUserPermissionsOption::eUpdateAppointment +
            enUserPermissionsOption::eFindAppointment;

    }
    int GetUserPermissions(enClinicRole role) {
        switch (role) {
        case enClinicRole::eSuperAdmin:
            return -1;
        case enClinicRole::eAdmin:
            return _GetAdminPermissions();
        case enClinicRole::eReceptionist:
            return _GetReceptionistPermissions();
        default:
            return 0;
        }
    }
    string _ConvertRoleToString()
    {
        return (_role == enClinicRole::eSuperAdmin) ? "SuperAdmin" :
            (_role == enClinicRole::eAdmin) ? "Admin" :
            (_role == enClinicRole::eReceptionist) ? "Receptionist" :
            "Unknown";
    }
    enClinicRole _ConvertStringToRole(string role)
    {
        return (role == "SuperAdmin") ? enClinicRole::eSuperAdmin :
            (role == "Admin") ? enClinicRole::eAdmin :
            (role == "Receptionist") ? enClinicRole::eReceptionist :
            enClinicRole::eUnknownRole;
    }
public:
  
    clsPermissions(enClinicRole role) {
        this->_role = role;
        this->_permissions = GetUserPermissions(role);
    }
    clsPermissions(string role): clsPermissions(_ConvertStringToRole(role)) {}
    clsPermissions(): clsPermissions(enClinicRole::eUnknownRole) {}

    void SetRole(enClinicRole role) {
        this->_role = role;
    }
    enClinicRole GetRole() {
        return this->_role;
    }
    __declspec(property(get = GetRole,put = SetRole)) enClinicRole Role;
    string GetStrRole()  {
        return _ConvertRoleToString();
    }
    __declspec(property(get = GetStrRole)) string StrRole;

    bool IsSuperAdmin() {
        return this->_role == enClinicRole::eSuperAdmin;
    }
    bool IsAdmin() {
        return this->_role == enClinicRole::eSuperAdmin && this->_role == enClinicRole::eAdmin;
    }
    bool IsUserHasPermissions(enUserPermissionsOption permissionType) {
        return (_permissions && permissionType) == permissionType;
    }
};