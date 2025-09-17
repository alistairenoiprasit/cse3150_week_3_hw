# cse3150 hw03
`Homework Week: 3`

`Name: Alistaire Noiprasit`

[![Run Pytest](https://github.com/alistairenoiprasit/cse3150_week_3_hw/actions/workflows/pytest.yaml/badge.svg)](https://github.com/alistairenoiprasit/cse3150_week_3_hw/actions/workflows/pytest.yaml)

I declare that:
- this assessment item is my own work, except where acknowledged, and has not been submitted for
academic credit elsewhere
- I certify that I have read and understood the University rules in respect of Student Academic
Misconduct.

<!--
> This work is ready for submission as of `Day XX Month 2025`. <br>
> This work is NOT ready for submission as of `Day XX MONTH 2025`. <br>
-->
> [!IMPORTANT]
> This work is ready for submission as of `17 Sep 2025`. <br>
> The final due date is `18 Sep 2025`.

SIGNED: ALISTAIRE NOIPRASIT

AI Declaration:
The github workflow automation was done using ChatGPT and is unrelated to course materials. 
(I just want to automate tests for pull requests).

# Assessment Content
## Provide short explanation of how you used pointers, const, references, casting, exceptions, and control flow
> [!NOTE]
> I used pointers for C-like strings such as char* name as well as pointers that would allow me to adjust the value of an element inside a table (for example using the gpaPointer to update the value of a student's GPA). I used const to make it clear, certain values such as names or elements of GPA table don't get modified inside a function. For example, GPA values shouldn't be updated, only read to calculate the Average GPA. I also used references such as &int size when passing values into avoid copying objects when passing into functions to improve efficiency. I used casting in AverageGPA to round up a double to an integer usiing static cast. Additionally, I used exception handling in the main loop to catch exceptions caused by functions such as addStudent when capacity of the array is reached. Finally, control flow was handled in the main menu loop, where a switch statement was used to identify one of the 5 integers in the command loop. The default would handle other entries. 

### Minor Notes
Instead of writing all the logic in the main function, I created a facade 'functions' for what I would have written in the main function for the respective sections (ie AddStudentFacade would take inputs, and throw any errors prior to calling addStudent) just so it wouldn't get so bloated and convoluted.

> [!CAUTION]
> I personally wasn't happy with the present implementation as I don't believe we should use integers to select, rather use characters, and use '1' character so that infinite loops or errors won't be thrown if the user enters a non-integer 'string' input that is attempted to be converted into an integer. As in the current version, it would create an infinite loop. Though not necessary, I have tried my best to mittigate the error by throwing an error and exiting the programming prior to the loop if we cannot pass an integer in just to avoid most of these scenarios.
