SELECT ID, EMAIL, FIRST_NAME, LAST_NAME  
FROM DEVELOPER_INFOS  
WHERE SKILL_1 = 'Python' || SKILL_2 = 'Python' || SKILL_3 = 'Python'  
ORDER BY ID ASC;