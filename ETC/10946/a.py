from time import sleep
from selenium import webdriver
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager
 

chrome_options = Options()
chrome_options.add_experimental_option("detach", True)

service = ChromeService(ChromeDriverManager().install())

browser = webdriver.Chrome(
    options=chrome_options, service=service
)

browser.get("https://www.acmicpc.net/login?next=%2F")
ID = "백준 id"
PW = "백준 pw"
 
login = browser.find_element(By.NAME,"login_user_id")
login.send_keys(ID)
login = browser.find_element(By.NAME,"login_password")
login.send_keys(PW)
 
browser.find_element(By.ID,"submit_button").click()
sleep(1)
while True:
    browser.get("본인이 전에 제출해서 틀렸던 페이지")
    sleep(1)
    browser.find_element(By.ID,"submit_button").click()
    sleep(72)
