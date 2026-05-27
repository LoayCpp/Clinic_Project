#pragma once
#include <string>

using namespace std;
class clsPermissions
{

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
        eShowAllPatients = 2,
        eUpdatePatient = 4,
        eFindPatient = 8,

        eManageDoctorsMenu = 16,
        eShowAllDoctors = 32,
        eAddNewDoctor = 64,
        eUpdateDoctor = 128,
        eDeleteDoctor = 256,
        eFindDoctor = 512,
        eUpdateDoctorsSpecialization = 1024,
        eUpdateDoctorsFeesRate = 2048,

        eManageUsersMenu = 4096,
        eShowAllUsers = 8192,
        eAddNewUser = 16384,
        eUpdateUser = 32768,
        eDeleteUser = 65536,
        eFindUser = 131072,
        eUpdateUsersPermissions = 262144,

        eManageAppointmentsMenu = 524288,
        eShowAllAppointments = 1048576,
        eAddNewAppointment = 2097152,
        eUpdateAppointment = 4194304,
        eDeleteAppointment = 8388608,
        eFindAppointment = 16777216
    };

private:
    enClinicRole _role;
    unsigned long long _permissions;

    unsigned long long _GetAdminPermissions()
    {
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
    unsigned long long _GetReceptionistPermissions()
    {
        return (int)enUserPermissionsOption::eManagePatientsMenu + enUserPermissionsOption::eShowAllPatients +
               enUserPermissionsOption::eUpdatePatient + enUserPermissionsOption::eFindPatient +
               enUserPermissionsOption::eManageDoctorsMenu + enUserPermissionsOption::eShowAllDoctors +
               enUserPermissionsOption::eFindDoctor +
               enUserPermissionsOption::eManageAppointmentsMenu + enUserPermissionsOption::eShowAllAppointments +
               enUserPermissionsOption::eAddNewAppointment + enUserPermissionsOption::eUpdateAppointment +
               enUserPermissionsOption::eFindAppointment;
    }
    unsigned long long GetUserPermissions(enClinicRole role)
    {
        switch (role)
        {
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
        return (_role == enClinicRole::eSuperAdmin) ? "SuperAdmin" : (_role == enClinicRole::eAdmin)      ? "Admin"
                                                                 : (_role == enClinicRole::eReceptionist) ? "Receptionist"
                                                                                                          : "Unknown";
    }
    enClinicRole _ConvertStringToRole(string role)
    {
        return (role == "SuperAdmin") ? enClinicRole::eSuperAdmin : (role == "Admin")      ? enClinicRole::eAdmin
                                                                : (role == "Receptionist") ? enClinicRole::eReceptionist
                                                                                           : enClinicRole::eUnknownRole;
    }

public:
    clsPermissions(enClinicRole role)
    {
        this->_role = role;
        this->_permissions = GetUserPermissions(role);
    }
    clsPermissions(string role) : clsPermissions(_ConvertStringToRole(role)) {}
    clsPermissions() : clsPermissions(enClinicRole::eUnknownRole) {}

    void SetRole(enClinicRole role)
    {
        this->_role = role;
    }
    enClinicRole GetRole()
    {
        return this->_role;
    }
    __declspec(property(get = GetRole, put = SetRole)) enClinicRole Role;
    string GetStrRole()
    {
        return _ConvertRoleToString();
    }
    __declspec(property(get = GetStrRole)) string StrRole;

    bool IsSuperAdmin()
    {
        return this->_role == enClinicRole::eSuperAdmin;
    }
    bool IsAdmin()
    {
        return this->_role == enClinicRole::eAdmin;
    }
    bool IsUserHasPermissions(clsPermissions::enClinicRole role, enUserPermissionsOption permissionType)
    {
        if (role == enClinicRole::eSuperAdmin)
        {
            return true;
        }
        if (role == enClinicRole::eUnknownRole)
        {
            return false;
        }
        else
            return (_permissions & permissionType) == permissionType;
    }
};