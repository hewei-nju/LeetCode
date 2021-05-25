import requests
from selenium import webdriver


driver = webdriver.Chrome()
teamNumber = 21100010007
url = 'https://www.mathorcup.org/cert_search?number=' + str(teamNumber)
driver.get(url)
number = driver.find_element_by_name('number')



# headers = {
#     "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/89.0.4389.82 Safari/537.36"}
# r = requests.post(url + str(teamNumber))
# r.text.findElementById
