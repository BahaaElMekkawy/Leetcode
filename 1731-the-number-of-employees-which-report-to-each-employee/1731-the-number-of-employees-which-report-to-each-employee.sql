SELECT 
    E.employee_id, 
    E.name, 
    COUNT(R.employee_id) AS reports_count,
    ROUND(AVG(R.age * 1.0), 0) AS average_age
FROM 
    Employees E,Employees R WHERE E.employee_id = R.reports_to
GROUP BY 
    E.employee_id, E.name  
ORDER BY 
    E.employee_id