/* https://www.codewars.com/kata/sql-easy-regex-extraction/train/sql */

SELECT name, greeting, substring(greeting from '#(\d+)') as user_id FROM greetings;