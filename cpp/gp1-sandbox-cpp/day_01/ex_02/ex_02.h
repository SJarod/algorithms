namespace day_01
{
    namespace ex_02
    {
        namespace box
        {
            int nb_little_boxes;

            struct other_box
            {
                int candy;
                int nb_little_boxes = day_01::ex_02::box::nb_little_boxes;

                enum candies
                {
                    ORANGE,
                    STRAWBERRY
                };
            };

            namespace little_box
            {
                int candies;
            }
        }
    }
}