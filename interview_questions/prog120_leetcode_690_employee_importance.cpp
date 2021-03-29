#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

class Employee
{
public:
    int id;
    int importance;
    std::vector<int> subordinates;
};

int sumofchilds(const std::unordered_map<int,int>& empMap, 
                const std::vector<Employee*>& employees,
                int currId)
{
    
    auto isId = [currId](Employee* e) {return e->id == currId;};
    auto resultIt = std::find_if(std::begin(employees), std::end(employees), isId);
    if (resultIt != std::end(employees))
    {
        int sum = (*resultIt)->importance;
        for (auto i = 0; i < (*resultIt)->subordinates.size() ; i++)
        {
            sum += sumofchilds(empMap, employees, (*resultIt)->subordinates[i]);
        }
        return sum;
    }
    return 0;
}
int getImportance(std::vector<Employee*> employees, int id) 
{
    std::unordered_map<int, int> empMap;

    for (auto it = employees.cbegin(); it != employees.cend(); it++)
    {
        empMap[(*it)->id] = (*it)->importance;
    }

    return sumofchilds(empMap, employees, id);
}

void printEmployees(std::vector<Employee*> employees)
{
    size_t numEmployees = employees.size();

    auto printSubordinates = [](const std::vector<int>& suboradinates){
            std::ostream_iterator<int> osIt {std::cout, " "};
            std::copy(suboradinates.cbegin(), suboradinates.cend(), osIt);
        };
    for(auto it = employees.cbegin(); it != employees.cend(); it++)
    {
        std::cout   << "\nid: " << (*it)->id 
                    << "\timporance: " << (*it)->importance 
                    << "\tsubordinates: "; printSubordinates((*it)->subordinates);
    }
    std::cout << std::endl;
}
int main()
{
    std::vector<Employee*>  employees;
    Employee* emp1 = new Employee();
    emp1->id = 1; emp1->importance = 5; emp1->subordinates = {2, 3};
    employees.push_back(emp1);
    emp1 = new Employee();
    emp1->id = 2; emp1->importance = 3; emp1->subordinates = {};
    employees.push_back(emp1);
    emp1 = new Employee();
    emp1->id = 3; emp1->importance = 3; emp1->subordinates = {};
    employees.push_back(emp1);
    printEmployees(employees);
    std::cout << getImportance(employees, 1) << std::endl;
    
    std::vector<Employee*>  employees2;
    emp1 = new Employee();
    emp1->id = 1; emp1->importance = 15; emp1->subordinates = {2};
    employees2.push_back(emp1);
    emp1 = new Employee();
    emp1->id = 2; emp1->importance = 10; emp1->subordinates = {3};
    employees2.push_back(emp1);
    emp1 = new Employee();
    emp1->id = 3; emp1->importance = 5; emp1->subordinates = {};
    employees2.push_back(emp1);
    printEmployees(employees2);
    std::cout << getImportance(employees2, 1) << std::endl;

}