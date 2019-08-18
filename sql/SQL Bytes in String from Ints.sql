/*  https://www.codewars.com/kata/59491429952ac97ad9000106/train/sql  */
SELECT
  OCTET_LENGTH(CAST (number1 AS VARCHAR(10))) AS octnum1,
  OCTET_LENGTH(CAST (number2 AS VARCHAR(10))) AS octnum2,
  OCTET_LENGTH(CAST (number3 AS VARCHAR(10))) AS octnum3,
  OCTET_LENGTH(CAST (number4 AS VARCHAR(10))) AS octnum4,
  OCTET_LENGTH(CAST (number5 AS VARCHAR(10))) AS octnum5
FROM numbers;